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
	p = pIn->GetUserAction();
}
void FillingAction::Execute()
{
	CFigure* f = pManager->Get_selected();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (p == BLACK1)
	{
		UI.FillColor = BLACK;
	}
	else if (p == YELLOW1)
	{
		UI.FillColor = YELLOW;
		UI.IsFilledNext = 1;
	}
	else if (p == BLUE1)
	{
		UI.FillColor = BLUE;
		UI.IsFilledNext = 1;

	}
	else if (p == RED1)
	{
		UI.FillColor = RED;
		UI.IsFilledNext = 1;

	}
	else if (p == GREEN1)
	{
		UI.FillColor = GREEN;
		UI.IsFilledNext = 1;
	}
	else if (p == ORANGE1)
	{
		UI.FillColor = ORANGE;
		UI.IsFilledNext = 1;
	}
	else if (p == transparent) {
		UI.FillColor = Transparent;
		UI.IsFilledNext = 0;
	}
	if (f != NULL)
	{
		CFigure* d1 = f->copy();
		d1->setID(f->GetID());
		pManager->AddUndo(d1);
		filling = pOut->getCrntFillColor();
		f->ChngFillClr(filling);
		UI.IsFilledNext = 1;
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