#include "DrawingAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
DrawingAction::DrawingAction(ApplicationManager* pApp) : Action(pApp)
{}

void DrawingAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType p = pIn->GetUserAction();
	if (p == BLACK1)
	{
		UI.DrawColor = BLACK;
	}

	else if (p == YELLOW1)
	{
		UI.DrawColor = YELLOW;
	}
	else if (p == BLUE1)
	{
		UI.DrawColor = BLUE;
	}
	else if (p == RED1)
	{
		UI.DrawColor = RED;
	}
	else if (p == GREEN1)
	{
		UI.DrawColor = GREEN;
	}
	else if (p == ORANGE1)
	{
		UI.DrawColor = ORANGE;
	}
}

void DrawingAction::Execute()
{
	ReadActionParameters();
	CFigure* f = pManager->Get_selected();
	Output* pOut = pManager->GetOutput();
	if (f != NULL)
	{
			drawing = pOut->getCrntDrawColor();
			f->ChngDrawClr(drawing);
			pManager->AddfigselectedC(f);
			pManager->Adddrawcolor(drawing);
			pManager->AddUndoAction(this);
			f->ChngDrawClr(drawing);
			if (pManager->GetIsRec())
			{
				CFigure* d1 = f->copy();
				d1->setID(f->GetID());
				pManager->AddRECFig(d1);
			}
	}
	else
		pOut->PrintMessage("Change Filling Color : select figure ");
}
