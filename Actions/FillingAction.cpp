#include "FillingAction.h"
#include "Action.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
FillingAction::FillingAction(ApplicationManager* pApp) : Action(pApp)
{}

void FillingAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	ActionType p = pIn->GetUserAction();
	if (p == BLACK1)
	{
		UI.FillColor = BLACK;
	}

	if (p  == YELLOW1)
	{
		UI.FillColor = YELLOW;
	}
	if (p  == BLUE1)
	{
		UI.FillColor = BLUE;
	}
	if (p  == RED1)
	{
		UI.FillColor = RED;
	}
	if (p  == GREEN1)
	{
		UI.FillColor = GREEN;
	}
	if (p == ORANGE1)
	{
		UI.FillColor = ORANGE;
	}
}
void FillingAction::Execute()
{
	CFigure* f = pManager->Get_selected();
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (f != NULL) {
		if (f->IsSelected())
		{
		filling = pOut->getCrntFillColor();
		f->ChngFillClr(filling);
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
}