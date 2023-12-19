#include "pick_both.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CHexa.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTri.h"
#include "..\Figures\CSquare.h"

pick_both::pick_both(ApplicationManager* pApp) :Action(pApp) {};//constructor

//Reads parameters required for action to execute (code depends on action type)
void pick_both::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
};

//Execute action (code depends on action type)
void pick_both::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->getfigcount() == 0) {
		pOut->PrintMessage("Invalid there is no figures to pick from.");
	}
	else {
		pManager->unhide();
		pManager->UpdateInterface();
		int col = rand() % 7;// generating random color to choose
		// 0 is red , 1 is blue , 2 is yellow , 3 is orange ,4 is green , 5 is black and 6 no fill
		int f = rand() % 5;// generating random figure to choose
		char t;
		int number; //calculating chosed figure
		// 0 is rect , 1 is square , 2 is triangle , 3 is circle ,4 is hexagon
		int t_count = 0; //true choices counter
		int f_count = 0; //wrong choices counter
		color x;
		string colour;
		switch (col) {
		case 0:
			x = RED;
			colour = "red";
			break;
		case 1:
			x = BLUE;
			colour = "blue";
			break;
		case 2:
			x = YELLOW;
			colour = "yellow";
			break;
		case 3:
			x = ORANGE;
			colour = "orange";
			break;
		case 4:
			x = GREEN;
			colour = "green";
			break;
		case 5:
			x = BLACK;
			colour = "black";
			break;
		case 6:
			x = GREY;
			colour = "non-filled";
			break;
		}
		switch (f) {
		case 0:
			t = 'R';
			number = pManager->count_fig(t,x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose " + colour + " Rectangles");
			break;
		case 1:
			t = 'S';
			number = pManager->count_fig(t, x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose " + colour + " Squares");
			break;
		case 2:
			t = 'T';
			number = pManager->count_fig(t, x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose " + colour + " Triangles");
			break;
		case 3:
			t = 'C';
			number = pManager->count_fig(t, x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose " + colour + " Circles");
			break;
		case 4:
			t = 'H';
			number = pManager->count_fig(t, x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose "+ colour+ " Hexagons");
			break;
		}
		while (number != 0) {
			ReadActionParameters();
			if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_both) {
				Execute();
				break;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure) {
				pManager->ExecuteAction(Pick_figure);
				break;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color) {
				pManager->ExecuteAction(PickColor);
				break;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
				pManager->ExecuteAction(TO_PLAY);
				break;
			}
			CFigure* d = pManager->GetFigure(P.x, P.y);
			if (d!=NULL&&!d->Ishidden()) {
				d->Sethidden(1);
				pManager->UpdateInterface();
				if (d->type()==t &&  d->get_color() == x) {
					number--;
					t_count++;
					pOut->PrintMessage("true selection count of true now is: " + to_string(t_count));
				}
				else {
					f_count++;
					pOut->PrintMessage("false selection count of false now is: " + to_string(f_count));
				}
			}
		}
		pManager->unhide();
		pManager->UpdateInterface();
		pOut->PrintMessage("Number of correct choices is " + to_string(t_count) + " Number of wrong choices is" + to_string(f_count));
	}
}