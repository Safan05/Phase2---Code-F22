#include "MoveByDrag.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
MoveByDrag::MoveByDrag(ApplicationManager* pApp) :Action(pApp)
{}

void MoveByDrag::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetMouseCord(d.x, d.y);
	pOut->ClearStatusBar();
}

void MoveByDrag::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* f = pManager->Get_selected();
	buttonstate B = BUTTON_DOWN;
	d.x = 0; d.y = 0;						
	if (f != NULL)
	{
		if (f->IsSelected()&& (B == BUTTON_DOWN))
		{
			while (B == BUTTON_DOWN) {
				B = pIn->GetLeftClickState();
				while(B==BUTTON_UP){ B = pIn->GetLeftClickState(); }
				Point M = d;
				pIn->GetMouseCord(d.x, d.y);
				ReadActionParameters();
				if (M.x != d.x && M.y != d.y) {
				ReadActionParameters();
					if (f->is_inside(d.x, d.y)) {
						f->Move(d, pOut);
						pManager->UpdateInterface();
						B = BUTTON_DOWN;
					}
					else {
						B = BUTTON_DOWN;
						break;
					}
				}
			}
		}
		else
			pOut->PrintMessage("Move Figure : select figure");
	}
}


