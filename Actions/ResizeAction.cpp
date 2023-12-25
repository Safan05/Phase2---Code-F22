#include "ResizeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ResizeAction::ResizeAction(ApplicationManager* pApp) :Action(pApp)
{}
void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetMouseCord(d.x, d.y);
	pOut->ClearStatusBar();
}

void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* f = pManager->Get_selected();
	buttonstate B = BUTTON_DOWN;
	d.x = 0; d.y = 0;
	bool flag = 0;
	if (f != NULL)
	{
		if (f->IsSelected() && (B == BUTTON_DOWN))
		{
			pOut->PrintMessage("Drag a point inside the figure");
			while (B == BUTTON_DOWN) {
				B = pIn->GetLeftClickState();
				while (B == BUTTON_UP) { B = pIn->GetLeftClickState(); }
				Point M = d;
				ReadActionParameters();
				if (M.x != d.x && M.y != d.y) {
					ReadActionParameters();
					if (f->is_inside(d.x, d.y) || flag) {
						flag = 1;
						f->Resize(d, pOut);
						pManager->UpdateInterface();
					}
					else {
						pOut->PrintMessage("The point must be inside the figure");
						break;
					}
				}
				B = pIn->GetLeftClickState();
			}
			if (pManager->GetIsRec())
			{
				CFigure* d1 = f->copy();
				d1->setID(f->GetID());

				pManager->AddRECFig(d1);
			}
		}
		else
			pOut->PrintMessage("Move Figure : select figure");
	}
}