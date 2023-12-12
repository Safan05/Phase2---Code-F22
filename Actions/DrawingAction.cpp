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

	if (p == YELLOW1)
	{
		UI.DrawColor = YELLOW;
	}
	if (p == BLUE1)
	{
		UI.DrawColor = BLUE;
	}
	if (p == RED1)
	{
		UI.DrawColor = RED;
	}
	if (p == GREEN1)
	{
		UI.DrawColor = GREEN;
	}
	if (p == ORANGE1)
	{
		UI.DrawColor = ORANGE;
	}
}

void DrawingAction::Execute()
{
	ReadActionParameters();
	CFigure* f = pManager->Get_selected();
	Output* pOut = pManager->GetOutput();
	if (f != NULL) {
		if (f->IsSelected())
		{
			drawing = pOut->getCrntDrawColor();

			f->ChngDrawClr(drawing);

		}
		else
			pOut->PrintMessage("Change Filling Color : select figure ");
	}
}
