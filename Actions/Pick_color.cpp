#include "Pick_color.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CHexa.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTri.h"
#include "..\Figures\CSquare.h"
Pick_color::Pick_color(ApplicationManager* pApp) :Action(pApp) {}//constructor

//Reads parameters required for action to execute (code depends on action type)
void Pick_color::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

//Execute action (code depends on action type)
void Pick_color::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->getfigcount() == 0) {
		pOut->PrintMessage("Invalid there is no figures to pick from.");
	}
	else {
		pManager->unhide();
		pManager->UpdateInterface();
		int col = rand() % 7;// generating random figure to choose
		// 0 is red , 1 is blue , 2 is yellow , 3 is orange ,4 is green , 5 is black and 6 no fill
		int t_count = 0; //true choices counter
		int f_count = 0; //wrong choices counter
		int number = 0;
		color x;
		switch (col) {
		case 0:
			x = RED;
			pOut->PrintMessage("You have to choose red figures");
			break;
		case 2:
			x = BLUE;
			pOut->PrintMessage("You have to choose blue figures");
			break;
		case 1:
			x = YELLOW;
			pOut->PrintMessage("You have to choose yellow figures");
			break;
		case 3:
			x = ORANGE;
			pOut->PrintMessage("You have to choose orange figures");
		case 4:
			x = GREEN;
			pOut->PrintMessage("You have to choose green figures");
			break;
		case 5:
			x = BLACK;
			pOut->PrintMessage("You have to choose black figures");
			break;
		case 6:
			x = Transparent;
			pOut->PrintMessage("You have to choose non-filled figures");
				break;
			}
		number = pManager->count_fig(x); //calculating chosed figure
		if (number == 0) {//if random generated figure DNE the program generates another one
			Execute();
			return;
		}
		while (number != 0) {
			ReadActionParameters();
			if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color) {
				Execute();
				return;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
				pManager->ExecuteAction(TO_PLAY);
				return;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure) {
				pManager->ExecuteAction(Pick_figure);
				return;
			}
			else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_both) {
				pManager->ExecuteAction(Pick_both);
				return;
			}
			CFigure* d = pManager->GetFigure(P.x, P.y);
			if (d != NULL&&!d->Ishidden()) {
				d->Sethidden(1);
				pManager->UpdateInterface();
				if (d->get_color() == x) {
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