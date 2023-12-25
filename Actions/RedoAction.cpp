#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "AddCircAction.h"
#include "AddHexaAction.h"
#include "AddRectAction.h"
#include "AddSquareAction.h"
#include "AddTriAction.h"
#include "delete_action.h"
#include "DrawingAction.h"
#include "FillingAction.h"
#include "MoveAction.h"
#include "..\Figures\CRectangle.h"
RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Redo Action");
	Action* b = pManager->GetfirstRedoAction();
	if (dynamic_cast<AddCircAction*>(b))
	{
		CFigure* f = pManager->GetlastRedoFig();
		pManager->AddFigure(f);
		//pManager->deleteRedoAction();
	}
	if (dynamic_cast<AddHexaAction*>(b))
	{
		CFigure* f = pManager->GetlastRedoFig();
		pManager->AddFigure(f);
		//pManager->deleteRedoAction();

	}
	if (dynamic_cast<AddRectAction*>(b))
	{
		CFigure* f = pManager->GetlastRedoFig();
		pManager->AddFigure(f);
		//pManager->deleteRedoAction();

	}
	if (dynamic_cast<AddSquareAction*>(b))
	{
		CFigure* f = pManager->GetlastRedoFig();
		pManager->AddFigure(f);
		//pManager->deleteRedoAction();

	}
	if (dynamic_cast<AddTriAction*>(b))
	{
		CFigure* f = pManager->GetlastRedoFig();
		pManager->AddFigure(f);
		//pManager->deleteRedoAction();

	}
	if (dynamic_cast<DrawingAction*>(b))
	{
		CFigure* f = pManager->GetfigSelectedC();
		f->Redocolordraw(pManager);
	}
	if (dynamic_cast<FillingAction*>(b))
	{

		CFigure* f = pManager->GetfigSelectedC();
		f->Redocolor(pManager);
	}
	if (dynamic_cast<MoveAction*>(b))
	{
		CFigure* f1 = pManager->GetfigselectedM();
		f1->RedoMove(pManager);
	}
	if (dynamic_cast<delete_action*>(b))
	{
	}

	//pManager->delRedoAction();
	//pManager->delfigredo();
}

void RedoAction::Execute()
{
	ReadActionParameters();
}