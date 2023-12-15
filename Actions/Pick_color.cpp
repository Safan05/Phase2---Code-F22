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
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose red figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		case 2:
			x = BLUE;
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose blue figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		case 1:
			x = YELLOW;
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose yellow figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		case 3:
			x = ORANGE;
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose orange figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		case 4:
			x = GREEN;
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose green figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		case 5:
			x = BLACK;
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose black figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		case 6:
			x = GRAY;
			number = pManager->count_fig(x); //calculating chosed figure
			if (number == 0)//if random generated figure DNE the program generates another one
				Execute();
			pOut->PrintMessage("You have to choose non-filled figures");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_color)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play) {
					pManager->ExecuteAction(TO_PLAY);
					break;
				}
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					if (!d->Ishidden() && d->get_color() == x) {
						d->Sethidden(1);
						pManager->UpdateInterface();
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
			break;
		}

	}
}