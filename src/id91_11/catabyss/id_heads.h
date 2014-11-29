/* Catacomb Abyss Source Code
 * Copyright (C) 1993-2014 Flat Rock Software
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

// ID_GLOB.H


//#include <ALLOC.H>
#include <ctype.h>
//#include <DOS.H>
#include <errno.h>
#include <fcntl.h>
//#include <IO.H>
//#include <MEM.H>
//#include <PROCESS.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
// for lseek and more
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define __ID_GLOB__

//--------------------------------------------------------------------------

// REF KEEN Use EXTENSION instead of EXT for simpler maintenance
#define EXTENSION "ABS"
//#define	EXT	"ABS"

// REF KEEN moved to bottom (where id0_char_t and more are defined)
// - also modified type for different platforms
//extern	id0_char_t id0_far introscn;

#include "gfxe_abs.h"
#include "audioabs.h"
#include "mapsabs.h"

//--------------------------------------------------------------------------

//
// DEFINES THE TILE ATTRIBUTE CHECKING CONVENTION (macros).
//
// DEFINE CUSTOM BIT-FLAG NAMES...
//


#define tf_SOLID							0x01
#define tf_SPECIAL						0x02
#define tf_EMBEDDED_KEY_COLOR			0x04

#define TILE_FLAGS(tile)   (tinf[FLAGS+(tile)])

#define GATE_KEY_COLOR(tile)		((id0_unsigned_char_t)(TILE_FLAGS(tile)>>4))

#define CAT3D

#define	TEXTGR	0
#define	CGAGR	1
#define	EGAGR	2
#define	VGAGR	3

#define  EGA320GR	10					// MDM (GAMERS EDGE)
#define  EGA640GR	11					// MDM (GAMERS EDGE)

#define GRMODE	EGAGR

#if GRMODE == EGAGR
#define GREXT	"EGA"
#endif
#if GRMODE == CGAGR
#define GREXT	"CGA"
#endif

//#define PROFILE

//
//	ID Engine
//	Types.h - Generic types, #defines, etc.
//	v1.0d1
//

#ifndef	__TYPES__
#define	__TYPES__

#include <stdint.h>
#include <stdbool.h>

typedef	bool id0_boolean_t;

// Should be UNSIGNED for VWL_MeasureString (high scores table) in Keen Dreams
// but SIGNED in Catacomb Abyss for which casting is done in VWL_MeasureString
// (and Keen Dreams' loadscn2)
typedef int8_t id0_char_t;

typedef int8_t id0_signed_char_t;
typedef uint8_t id0_unsigned_char_t;
typedef int16_t id0_short_t; // Possibly used in kd_main.c and external decompression routines for Keen Dreams
typedef int16_t id0_int_t;
typedef uint16_t id0_unsigned_t;
typedef uint16_t id0_unsigned_int_t; // Found in shareware release v1.13
typedef int32_t id0_long_t;
typedef int32_t id0_signed_long_t;
typedef uint32_t id0_unsigned_long_t;

typedef uint8_t id0_byte_t;
typedef uint16_t id0_word_t;
typedef uint32_t id0_longword_t;
//typedef uint8_t * id0_ptr_t; // Ptr; Looks unused in Catacomb Abyss (and only kind-of used in Keen Dreams)

typedef	struct
		{
			id0_int_t	x,y;
		} Point;
typedef	struct
		{
			Point	ul,lr;
		} Rect;

#define	id0_nil_t	((void *)0)

// TODO (REF KEEN): These should really be removed, but just for now and to document...
#define id0_far
#define id0_huge
#define id0_seg

#endif

// FIXME (REF KEEN) a real hack for now
#ifndef O_BINARY
#define O_BINARY 0
#endif

// (REF KEEN) VANILLA BUG REPRODUCTION: In the original code, a call to
// VW_DrawPic on startup leaves the map mask value at 8 (intensity plane),
// so numbers aren't drawn in the following call to RedrawStatusWindow.
// We add a workaround here since we don't store EGA write/read mode
// related values internally (we almost don't need these).
extern bool id0_workaround_catabyss_exe_nodraw_digits_on_startup;

// Initialized before calling vanilla app's (now renamed) main function
extern int id0_argc;
extern char **id0_argv;

extern id0_char_t *introscn;

#include "be_sdl.h"

#include "id_mm.h"
#include "id_ca.h"
#include "id_vw.h"
#include "id_in.h"
#include "id_sd.h"
#include "id_us.h"

#include "be_cross.h"


void	Quit (id0_char_t *error, ...);		// defined in user program

//
// replacing refresh manager with custom routines
//

#define	PORTTILESWIDE		21      // all drawing takes place inside a
#define	PORTTILESHIGH		14		// non displayed port of this size

#define UPDATEWIDE			(PORTTILESWIDE+1)
#define UPDATEHIGH			PORTTILESHIGH

#define	MAXTICS				6
#define DEMOTICS			3

#define	UPDATETERMINATE	0x0301

extern	id0_unsigned_t	mapwidth,mapheight,tics,realtics;
extern	id0_boolean_t		compatability;

extern	id0_byte_t		*updateptr;
extern	id0_unsigned_t	uwidthtable[UPDATEHIGH];
extern	id0_unsigned_t	blockstarts[UPDATEWIDE*UPDATEHIGH];