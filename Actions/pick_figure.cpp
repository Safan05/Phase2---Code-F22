#include "pick_figure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CHexa.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTri.h"
#include "..\Figures\CSquare.h"

pick_figure::pick_figure(ApplicationManager* pApp) :Action(pApp) {};//constructor

//Reads parameters required for action to execute (code depends on action type)
void pick_figure::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
};

//Execute action (code depends on action type)
void pick_figure::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->getfigcount() == 0) {
		pOut->PrintMessage("Invalid there is no figures to pick from.");
	}
	else {
		pManager->unhide();
		pManager->UpdateInterface();
		int f = rand() % 5;// generating random figure to choose
		char t;
		int number; //calculating chosed figure
		// 0 is rect , 1 is square , 2 is triangle , 3 is circle ,4 is hexagon
		switch (f) {
		case 0:
			t = 'R';
			pOut->PrintMessage("You have to choose Rectangles");
			break;
		case 1:
			t = 'S';
			pOut->PrintMessage("You have to choose Squares");
			break;
		case 2:
			t = 'T';
			pOut->PrintMessage("You have to choose Triangles");
			break;
		case 3:
			t = 'C';
			pOut->PrintMessage("You have to choose Circles");
			break;
		case 4:
			t = 'H';
			pOut->PrintMessage("You have to choose Hexagons");
			break;
		}
		number = pManager->count_fig(t); //calculating chosed figure
		if (number == 0) {//if random generated figure DNE the program generates another one
			Execute();
			return;
		}
		int t_count = 0; //true choices counter
		int f_count = 0; //wrong choices counter
		while (number != 0) {
			ReadActionParameters();
			if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure) {
				Execute();
				return;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
				pManager->ExecuteAction(TO_PLAY);
				return;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_both) {
				pManager->ExecuteAction(Pick_both);
				return;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color) {
				pManager->ExecuteAction(PickColor);
				return;
			}
			CFigure* d = pManager->GetFigure(P.x, P.y);
			if (d != NULL&& !d->Ishidden()) {
				d->Sethidden(1);
				pManager->UpdateInterface();
				if (d->type() == t) {
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