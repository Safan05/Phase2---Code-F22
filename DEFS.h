#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,     //Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRI,
	DRAW_CIRC,
	DRAW_HEXA,
	FIGURES,
	BACK_TO_DRAW,
	SELECT,
	DELETE_FIG,
	CLEAR_ALL,
	Save_graph,
	load_graph,
	EXIT,			//Exit
	Start_Rec,
	Stop_Rec,
	Play_Rec,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	TO_PICK,
	Pick_color,
	Pick_figure,
	Pick_both,
	UNDO,
	REDO,
	FILLING,
	DRAWING,
	BLACK1,
	YELLOW1,
	ORANGE1,
	RED1,
	GREEN1,
	BLUE1,
	MOVE,
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif