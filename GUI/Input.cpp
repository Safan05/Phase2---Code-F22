#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

buttonstate Input::GetLeftClickState() const
{
	int x, y;
	pWind->GetMouseCoord(x, y);
	return pWind->GetButtonState(LEFT_BUTTON, x, y);
}

void Input::GetMouseCord(int& x, int& y) const
{
	pWind->GetMouseCoord(x,y);
}


string Input::GetString(Output* pO) const
{
	pWind->FlushKeyQueue();
	string Label;
	char Key;
	while (1)
	{
		pWind->FlushMouseQueue();
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_FIGURES: return FIGURES;
			case ITM_SELECT: return SELECT;
			case ITM_DELETE: return DELETE_FIG;
			case ITM_CLEAR: return CLEAR_ALL;
			case ITM_StartRecording:return Start_Rec;
			case ITM_StopRecording:return Stop_Rec;
			case ITM_PlayRecord:return Play_Rec;
			case ITM_Switch_Play:return TO_PLAY;
			case ITM_EXIT: return EXIT;
			case ITM_SAVEGRAPH: return Save_graph;
			case ITM_LOADGRAPH: return load_graph;
			case ITM_UNDO:  return UNDO;
			case ITM_REDO:  return REDO;
			case ITM_FILLING:  return FILLING;
			case ITM_DRAWING:  return DRAWING;
			case ITM_BLACK1:  return BLACK1;
			case ITM_YELLOW1:  return YELLOW1;
			case ITM_ORANGE1:  return ORANGE1;
			case ITM_RED1:   return RED1;
			case ITM_GREEN1:  return GREEN1;
			case ITM_BLUE1:   return BLUE1;
			case ITM_MOVE:  return MOVE;
			case ITM_MOVEBYDRAG:  return MOVEBYDRAG;
			case ITM_Voice: return Voice;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY) 	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Switch_Draw:return TO_DRAW;
			case ITM_Pick:return TO_PICK;
			case ITM_EXIT_Play: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

		//return TO_PLAY;	//just for now. This should be updated
	}
	else if (UI.InterfaceMode == MODE_PICK) 	//GUI is in Pick mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Pick_color:return PickColor;
			case ITM_Pick_figure:return Pick_figure;
			case ITM_Pick_both:return Pick_both;
			case ITM_Back_play:return TO_PLAY;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

		//return TO_PLAY;	//just for now. This should be updated
	}
	else {              //GUI FIGURES
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_HEXA:return DRAW_HEXA;
			case ITM_SWITCH:return BACK_TO_DRAW;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
}
/////////////////////////////////

Input::~Input()
{
}
