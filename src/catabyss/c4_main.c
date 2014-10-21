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

// C3_MAIN.C
#define CATALOG


#include <time.h>
#include <stdarg.h>

#include "def.h"
#include "gelib.h"
#pragma hdrstop
//#include <dir.h>

/*
=============================================================================


=============================================================================
*/

/*
=============================================================================

						 LOCAL CONSTANTS

=============================================================================
*/


/*
=============================================================================

						 GLOBAL VARIABLES

=============================================================================
*/

textinfo MainHelpText;

GameDiff restartgame;
id0_boolean_t loadedgame,abortgame,ingame;


memptr		scalesegs[NUMPICS];
id0_char_t		str[80],str2[20];
id0_unsigned_t	tedlevelnum;
id0_boolean_t		tedlevel;
gametype	gamestate;
exittype	playstate;
id0_char_t	SlowMode = 0;
id0_int_t starting_level;
id0_boolean_t EASYMODEON;

id0_short_t NumGames=0;
id0_unsigned_t Flags=0;

void DisplayIntroText(void);

/*
=============================================================================

						 LOCAL VARIABLES

=============================================================================
*/



//===========================================================================

#if 0
// JAB Hack begin
#define	MyInterrupt	0x60
void interrupt (*intaddr)();
void interrupt (*oldintaddr)();
	id0_char_t	*JHParmStrings[] = {"no386",nil};

void
jabhack(void)
{
extern void id0_far jabhack2(void);
extern id0_int_t id0_far	CheckIs386(void);

	id0_int_t	i;

	oldintaddr = getvect(MyInterrupt);

	for (i = 1;i < id0_argc;i++)
		if (US_CheckParm(id0_argv[i],JHParmStrings) == 0)
			return;

	if (CheckIs386())
	{
		jabhack2();
		setvect(MyInterrupt,intaddr);
	}
}

void
jabunhack(void)
{
	setvect(MyInterrupt,oldintaddr);
}
//	JAB Hack end
#endif

//===========================================================================

/*
=====================
=
= NewGame
=
= Set up new game to start from the beginning
=
=====================
*/

void NewGame (void)
{
	if (!loadedgame)
	{
		memset (&gamestate,0,sizeof(gamestate));
		gamestate.mapon = starting_level;
		gamestate.body = MAXBODY;
	}

	BGFLAGS = 0;
	Flags &= FL_CLEAR;

	boltsleft = bolttimer = 0;
	FreezeTime = 0;

//	memset (gamestate.levels,-1,sizeof(gamestate.levels));
}

//===========================================================================

#define RLETAG	0xABCD

/*
==================
=
= SaveTheGame
=
==================
*/

id0_boolean_t	SaveTheGame(int file)
{
	id0_word_t	i,compressed,expanded;
	objtype	*o;
	memptr	bigbuffer;

	if (!CA_FarWrite(file,(void id0_far *)&FreezeTime,sizeof(FreezeTime)))
		return(false);

	if (!CA_FarWrite(file,(void id0_far *)&gamestate,sizeof(gamestate)))
		return(false);

	if (!CA_FarWrite(file,(void id0_far *)&EASYMODEON,sizeof(EASYMODEON)))
		return(false);

	expanded = mapwidth * mapheight * 2;
	MM_GetPtr (&bigbuffer,expanded);

	for (i = 0;i < 3;i+=2)	// Write planes 0 and 2
	{
//
// leave a id0_word_t at start of compressed data for compressed length
//
		compressed = (id0_unsigned_t)CA_RLEWCompress ((id0_unsigned_t id0_huge *)mapsegs[i]
			,expanded,((id0_unsigned_t id0_huge *)bigbuffer)+1,RLETAG);

		*(id0_unsigned_t id0_huge *)bigbuffer = compressed;

		if (!CA_FarWrite(file,(void id0_far *)bigbuffer,compressed+2) )
		{
			MM_FreePtr (&bigbuffer);
			return(false);
		}
	}

	for (o = player;o;o = o->next)
		if (!CA_FarWrite(file,(void id0_far *)o,sizeof(objtype)))
		{
			MM_FreePtr (&bigbuffer);
			return(false);
		}

	MM_FreePtr (&bigbuffer);

	return(true);
}

//===========================================================================

/*
==================
=
= LoadTheGame
=
==================
*/

id0_boolean_t	LoadTheGame(int file)
{
	id0_unsigned_t	i,x,y;
	objtype		*obj,*prev,*next,*followed;
	id0_unsigned_t	compressed,expanded;
	id0_unsigned_t	id0_far *map,tile;
	memptr		bigbuffer;

	screenpage = 0;
	FreeUpMemory();

	playstate = ex_loadedgame;
	if (!CA_FarRead(file,(void id0_far *)&FreezeTime,sizeof(FreezeTime)))
		return(false);

	if (!CA_FarRead(file,(void id0_far *)&gamestate,sizeof(gamestate)))
		return(false);

	if (!CA_FarRead(file,(void id0_far *)&EASYMODEON,sizeof(EASYMODEON)))
		return(false);

	SetupGameLevel ();		// load in and cache the base old level

	if (!FindFile(Filename,"SAVE GAME",-1))
		Quit("Error: Can't find saved game file!");

	expanded = mapwidth * mapheight * 2;
	MM_GetPtr (&bigbuffer,expanded);

	for (i = 0;i < 3;i+=2)	// Read planes 0 and 2
	{
		if (!CA_FarRead(file,(void id0_far *)&compressed,sizeof(compressed)) )
		{
			MM_FreePtr (&bigbuffer);
			return(false);
		}

		if (!CA_FarRead(file,(void id0_far *)bigbuffer,compressed) )
		{
			MM_FreePtr (&bigbuffer);
			return(false);
		}

		CA_RLEWexpand ((id0_unsigned_t id0_huge *)bigbuffer,
			(id0_unsigned_t id0_huge *)mapsegs[i],expanded,RLETAG);
	}

	MM_FreePtr (&bigbuffer);
//
// copy the wall data to a data segment array again, to handle doors and
// bomb walls that are allready opened
//
	memset (tilemap,0,sizeof(tilemap));
	memset (actorat,0,sizeof(actorat));
	map = mapsegs[0];
	for (y=0;y<mapheight;y++)
		for (x=0;x<mapwidth;x++)
		{
			tile = *map++;
			if (tile<NUMFLOORS)
			{
				tilemap[x][y] = tile;
				if (tile>0)
					actorat[x][y] = tile;
					//(id0_unsigned_t)actorat[x][y] = tile;
			}
		}


	// Read the object list back in - assumes at least one object in list

	InitObjList ();
	new = player;
	while (true)
	{
		prev = new->prev;
		next = new->next;
		if (!CA_FarRead(file,(void id0_far *)new,sizeof(objtype)))
			return(false);
		followed = new->next;
		new->prev = prev;
		new->next = next;
		actorat[new->tilex][new->tiley] = COMPAT_OBJ_CONVERT_OBJ_PTR_TO_DOS_PTR(new);
		//actorat[new->tilex][new->tiley] = new;	// drop a new marker

		if (followed)
			GetNewObj (false);
		else
			break;
	}

	return(true);
}

//===========================================================================

/*
==================
=
= ResetGame
=
==================
*/

void ResetGame(void)
{
	NewGame ();

	ca_levelnum--;
	ca_levelbit>>=1;
	CA_ClearMarks();
	ca_levelbit<<=1;
	ca_levelnum++;
}

//===========================================================================


/*
==========================
=
= ShutdownId
=
= Shuts down all ID_?? managers
=
==========================
*/

void ShutdownId (void)
{
  US_Shutdown ();
#ifndef PROFILE
  SD_Shutdown ();
  IN_Shutdown ();
#endif
  VW_Shutdown ();
  CA_Shutdown ();
  MM_Shutdown ();
}


//===========================================================================

/*
==========================
=
= InitGame
=
= Load a few things right away
=
==========================
*/

void InitGame (void)
{
	id0_unsigned_t	segstart,seglength;
	id0_int_t			i,x,y;
	id0_unsigned_t	*blockstart;

//	US_TextScreen();

	MM_Startup ();
	VW_Startup ();
#ifndef PROFILE
	IN_Startup ();
	SD_Startup ();
#endif
	US_Startup ();

//	US_UpdateTextScreen();

	CA_Startup ();
	US_Setup ();

	US_SetLoadSaveHooks(LoadTheGame,SaveTheGame,ResetGame);


//
// load in and lock down some basic chunks
//

	CA_ClearMarks ();

	CA_MarkGrChunk(STARTFONT);
	CA_MarkGrChunk(STARTTILE8);
	CA_MarkGrChunk(STARTTILE8M);
	CA_MarkGrChunk(HAND1PICM);

	CA_MarkGrChunk(NORTHICONSPR);
	CA_CacheMarks (NULL);

	MM_SetLock (&grsegs[STARTFONT],true);
	MM_SetLock (&grsegs[STARTTILE8],true);
	MM_SetLock (&grsegs[STARTTILE8M],true);
	MM_SetLock (&grsegs[HAND1PICM],true);

	fontcolor = WHITE;


//
// build some tables
//
	for (i=0;i<MAPSIZE;i++)
		nearmapylookup[i] = &tilemap[0][0]+MAPSIZE*i;

	for (i=0;i<PORTTILESHIGH;i++)
		uwidthtable[i] = UPDATEWIDE*i;

	blockstart = &blockstarts[0];
	for (y=0;y<UPDATEHIGH;y++)
		for (x=0;x<UPDATEWIDE;x++)
			*blockstart++ = SCREENWIDTH*16*y+x*TILEWIDTH;

	BuildTables ();			// 3-d tables

	SetupScaling ();

#ifndef PROFILE
//	US_FinishTextScreen();
#endif

#if 0
//
// reclaim the memory from the linked in text screen
//
	segstart = FP_SEG(&introscn);
	seglength = 4000/16;
	if (FP_OFF(&introscn))
	{
		segstart++;
		seglength--;
	}
	MML_UseSpace (segstart,seglength);
#endif

	VW_SetScreenMode (GRMODE);
	ge_textmode = false;
//	VW_ColorBorder (3);
	VW_ClearVideo (BLACK);

//
// initialize variables
//
	updateptr = &update[0];
	*(id0_unsigned_t *)(updateptr + UPDATEWIDE*PORTTILESHIGH) = UPDATETERMINATE;
	bufferofs = 0;
	displayofs = 0;
	VW_SetLineWidth(SCREENWIDTH);
}

//===========================================================================

//void clrscr (void);		// can't include CONIO.H because of name conflicts...

/*
==========================
=
= Quit
=
==========================
*/

void Quit (id0_char_t *error, ...)
{
	id0_short_t exit_code=0;
	id0_unsigned_t	finscreen;

	va_list ap;

	va_start(ap,error);

	if (!error)
	{
		CA_SetAllPurge ();
#ifndef CATALOG
		CA_CacheGrChunk (PIRACY);
		finscreen = (id0_unsigned_t)grsegs[PIRACY];
#endif
	}
	ShutdownId ();

	if (error && *error)
	{
		// FIXME FIXME FIXME (CHOCO CAT)
		BE_Cross_Simplified_printf(error);
		//vprintf(error,ap);
		exit_code = 1;
	}

#ifndef CATALOG
	else
	{
		movedata (finscreen,0,0xb800,0,4000);

		if (kbhit())
		{
			while (kbhit())
				bioskey(0);
		}

		bioskey (0);
	}
#endif

	va_end(ap);

#ifndef CATALOG
	if (!error)
	{
		id0_argc = 2;
		id0_argv[1] = "LAST.SHL";
		id0_argv[2] = "ENDSCN.SCN";
		id0_argv[3] = NULL;
		if (execv("LOADSCN.EXE", id0_argv) == -1)
		{
			BE_SDL_clrscr();
			BE_Cross_puts("Couldn't find executable LOADSCN.EXE.\n");
			BE_SDL_HandleExit(1);
		}
	}
#endif

	BE_SDL_HandleExit(exit_code);
}

//===========================================================================

/*
==================
=
= TEDDeath
=
==================
*/

void	TEDDeath(void)
{
	ShutdownId();
	execlp("TED5.EXE","TED5.EXE","/LAUNCH",NULL);
}

//===========================================================================

/*
=====================
=
= DemoLoop
=
=====================
*/

void	DemoLoop (void)
{
/////////////////////////////////////////////////////////////////////////////
// main game cycle
/////////////////////////////////////////////////////////////////////////////

//	displayofs = bufferofs = 0;
//	VW_Bar (0,0,320,200,0);
//	VW_SetScreen(0,0);

//	set EASYMODE
//
	if (BE_Cross_strcasecmp(id0_argv[2], "1") == 0)
		EASYMODEON = true;
	else
		EASYMODEON = false;

// restore game
//
	if (BE_Cross_strcasecmp(id0_argv[3], "1") == 0)
	{
		VW_FadeOut();
		bufferofs = displayofs = 0;
		VW_Bar(0,0,320,200,0);
		if (GE_LoadGame())
		{
			loadedgame = true;
			playstate = ex_loadedgame;
			Keyboard[sc_Enter] = true;
			VW_Bar(0,0,320,200,0);
			ColoredPalette();
		}
		VW_Bar(0,0,320,200,0);
		VW_FadeIn();
	}

	// Play a game
	//
		restartgame = gd_Normal;
		NewGame();
		GameLoop();
}

//-------------------------------------------------------------------------
// DisplayIntroText()
//-------------------------------------------------------------------------
void DisplayIntroText()
{
	id0_char_t *toptext = "You stand before the gate leading into the Towne "
						 "Cemetery. Night is falling as mournful wails mingle "
						 "with the sound of your pounding heart.";

	id0_char_t *bottomtext = "Equipped with your wits and the Secret Knowledge of "
							 "Magick, you venture forth on your quest to upset "
							 "the dark schemes of Nemesis, your arch rival.";

	id0_char_t oldfontcolor=fontcolor;

	fontcolor = 14;
	WindowX=WindowY=0;
	PPT_RightEdge=319;
	PPT_LeftEdge=0;

	PrintY = 1;
	PrintPropText(toptext);

	PrintY = 160;
	PrintPropText(bottomtext);

	fontcolor = oldfontcolor;
}

#if 0
id0_boolean_t ChooseGameLevel()
{
	id0_char_t choices[] = {sc_Escape,sc_E,sc_N,sc_H,0},ch;

	CenterWindow(20,10);

	US_Print("\n   Choose difficulty level:\n");
	US_Print("       (E)asy\n");
	US_Print("       (N)ormal\n");
	US_Print("       (H)ard\n");
	US_Print("\n      (ESC)ape aborts\n");

//	VW_UpdateScreen();
	if ((ch=GetKeyChoice(choices)) == sc_Escape)
	{
		while (Keyboard[sc_Escape]);
		LastScan = 0;
		return(false);
	}

	if (ch == sc_E)
		restartgame = gd_Easy;
	else
	if (ch == sc_N)
		restartgame = gd_Normal;
	else
		restartgame = gd_Hard;

	return(true);
}
#endif


//===========================================================================

/*
==========================
=
= SetupScalePic
=
==========================
*/

void SetupScalePic (id0_unsigned_t picnum)
{
	id0_unsigned_t	scnum;

	if (picnum == 1)
		return;

	scnum = picnum-FIRSTSCALEPIC;

	if (shapedirectory[scnum])
	{
		MM_SetPurge ((memptr *)&shapedirectory[scnum],0);
		return;					// allready in memory
	}

	CA_CacheGrChunk (picnum);
	DeplanePic (picnum);
	shapesize[scnum] = BuildCompShape (&shapedirectory[scnum]);
	grneeded[picnum]&= ~ca_levelbit;
	MM_FreePtr (&grsegs[picnum]);
}

//===========================================================================

/*
==========================
=
= SetupScaleWall
=
==========================
*/

void SetupScaleWall (id0_unsigned_t picnum)
{
	id0_int_t		x,y;
	id0_unsigned_t	scnum;
	id0_byte_t	id0_far *dest;

	if (picnum == 1)
		return;

	scnum = picnum-FIRSTWALLPIC;

	if (walldirectory[scnum])
	{
		MM_SetPurge (&walldirectory[scnum],0);
		return;					// allready in memory
	}

	CA_CacheGrChunk (picnum);
	DeplanePic (picnum);
	MM_GetPtr(&walldirectory[scnum],64*64);
	dest = (id0_byte_t id0_far *)walldirectory[scnum];
	for (x=0;x<64;x++)
		for (y=0;y<64;y++)
			*dest++ = spotvis[y][x];
	grneeded[picnum]&= ~ca_levelbit;
	MM_FreePtr (&grsegs[picnum]);
}

//===========================================================================

/*
==========================
=
= SetupScaling
=
==========================
*/

void SetupScaling (void)
{
	id0_int_t		i,x,y;
	id0_byte_t	id0_far *dest;

//
// build the compiled scalers
//
	for (i=1;i<=VIEWWIDTH/2;i++)
		BuildCompScale (i*2,&scaledirectory[i]);
}

//===========================================================================

id0_int_t	showscorebox;

void RF_FixOfs (void)
{
}

void HelpScreens (void)
{
}


#if 0
/*
==================
=
= CheckMemory
=
==================
*/

#define MINMEMORY	400000l

void	CheckMemory(void)
{
	id0_unsigned_t	finscreen;

	if (Flags & FL_NOMEMCHECK)
		return;

	if (mminfo.nearheap+mminfo.farheap+mminfo.EMSmem+mminfo.XMSmem
		>= MINMEMORY)
		return;

	CA_CacheGrChunk (OUTOFMEM);
	finscreen = (id0_unsigned_t)grsegs[OUTOFMEM];
	ShutdownId ();
	movedata (finscreen,7,0xb800,0,4000);
	gotoxy (1,24);
	exit(1);
}
#endif

//===========================================================================


/*
==========================
=
= main
=
==========================
*/

id0_char_t			*MainParmStrings[] = {"q","l","ver","nomemcheck",id0_nil_t};
id0_boolean_t		LaunchedFromShell = false;

int id0_argc;
char **id0_argv;

void id0_main (void)
{
	id0_short_t i;

	starting_level = 0;

	for (i = 1;i < id0_argc;i++)
	{
		switch (US_CheckParm(id0_argv[i],MainParmStrings))
		{
			case 0:
				Flags |= FL_QUICK;
			break;

			case 1:
				starting_level = atoi(id0_argv[i]+1);
				if ((starting_level < 0) || (starting_level > LASTMAP-1))
					starting_level = 0;
			break;

			case 2:
				// TODO (CHOCO CAT) Should we fix this?
				// It is a simplified printf after all...
				BE_Cross_Simplified_printf(GAMENAME);
				BE_Cross_Simplified_printf("  ");
				BE_Cross_Simplified_printf(VERSION);
				BE_Cross_Simplified_printf("  rev ");
				BE_Cross_Simplified_printf(REVISION);
				BE_Cross_Simplified_printf("\n");
				//BE_Cross_Simplified_printf("%s  %s  rev %s\n",GAMENAME,VERSION,REVISION);
				BE_SDL_HandleExit(0);
			break;

			case 3:
				Flags |= FL_NOMEMCHECK;
			break;
		}
	}

	if (!BE_Cross_strcasecmp(id0_argv[1], "^(a@&r`"))
			LaunchedFromShell = true;

	// CHOCO CAT difference from vanilla Catacomb Abyss:
	// Role of argument "^(a@&r`" has been flipped. No need to pass it
	// (or use start), but if it is added then you get this message.
	if (LaunchedFromShell)
	{
		BE_SDL_clrscr();
		BE_Cross_puts("You must type CATABYSS at the DOS prompt to run CATACOMB ABYSS 3-D.");
		BE_SDL_HandleExit(0);
	}

	BE_Cross_Brandomize();

	InitGame ();
	LoadLatchMem ();

#ifdef PROFILE
	NewGame ();
	GameLoop ();
#endif

	DemoLoop();
	Quit(NULL);
}