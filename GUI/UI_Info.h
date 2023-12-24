#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_FIGURES,
	MODE_PICK
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_FIGURES,
	ITM_UNDO,
	ITM_REDO,
	ITM_FILLING,
	ITM_DRAWING,
	ITM_BLACK1,
	ITM_YELLOW1,
	ITM_ORANGE1,
	ITM_RED1,
	ITM_GREEN1,
	ITM_BLUE1,
	ITM_TRANSPARENT,
	ITM_MOVE,
	ITM_MOVEBYDRAG,
	ITM_RESIZE,
	ITM_SELECT,
	ITM_DELETE,
	ITM_CLEAR,
	ITM_Voice,
	ITM_StartRecording,
	ITM_StopRecording,
	ITM_PlayRecord,
	ITM_SAVEGRAPH,
	ITM_LOADGRAPH,
	ITM_Switch_Play,
	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};
enum Figures {
	ITM_RECT,
	ITM_SQUARE,
	ITM_TRI,
	ITM_CIRC,
	ITM_HEXA,
	ITM_SWITCH,
	FIGURE_COUNT
};
enum Pick {
	ITM_Pick_color,
	ITM_Pick_figure,
	ITM_Pick_both,
	ITM_Back_play,
	Pick_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_Pick,
	ITM_Switch_Draw,
	ITM_EXIT_Play,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;
	int PenWidth;			//width of the pen that draws shapes
	bool IsFilledNext;
	/// Add more members if needed

}UI;	//create a global object UI

#endif