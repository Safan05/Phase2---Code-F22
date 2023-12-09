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
		// 0 is rect , 1 is square , 2 is triangle , 3 is circle ,4 is hexagon
		int t_count = 0; //true choices counter
		int f_count = 0; //wrong choices counter
		int number = pManager->count_fig(f); //calculating chosed figure
		if (number == 0)//if random generated figure DNE the program generates another one
			Execute();
		switch (f)
		{
		case ITM_RECT:
			pOut->PrintMessage("You have to choose rectangles");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play)
					break;
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					CRectangle* r = dynamic_cast<CRectangle*>(d);
					if (r && !d->Ishidden()) {
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
		case ITM_CIRC:
			pOut->PrintMessage("You have to choose circles");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play)
					break;
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					CCirc* c = dynamic_cast<CCirc*>(d);
					if (c && !d->Ishidden()) {
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
		case ITM_SQUARE:
			pOut->PrintMessage("You have to choose squares");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play)
					break;
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					CSquare* s = dynamic_cast<CSquare*>(d);
					if (s && !s->Ishidden()) {
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
		case ITM_HEXA:
			pOut->PrintMessage("You have to choose hexagons");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play)
					break;
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					CHexa* h = dynamic_cast<CHexa*>(d);
					if (h && !h->Ishidden()) {
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
		case ITM_TRI:
			pOut->PrintMessage("You have to choose triangles");
			while (number != 0) {
				ReadActionParameters();
				if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Pick_figure)
					Execute();
				else if (P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == ITM_Back_play)
					break;
				CFigure* d = pManager->GetFigure(P.x, P.y);
				if (d != NULL) {
					CTri* t = dynamic_cast<CTri*>(d);
					if (t && !t->Ishidden()) {
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