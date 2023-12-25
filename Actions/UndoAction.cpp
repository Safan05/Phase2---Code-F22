#include "UndoAction.h"
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
UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
}

void UndoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Undo Action");
	Action* c = pManager->GetlastUndo();
	pManager->delUndocount();
	if (dynamic_cast<AddCircAction*>(c))
	{
		pManager->deletelastfig();
	}
	if (dynamic_cast<AddHexaAction*>(c))
	{
		pManager->deletelastfig();
	}
	if (dynamic_cast<AddRectAction*>(c))
	{
		pManager->deletelastfig();
	}
	if (dynamic_cast<AddSquareAction*>(c))
	{
		pManager->deletelastfig();
	}
	if (dynamic_cast<AddTriAction*>(c))
	{
		pManager->deletelastfig();
	}
	if (dynamic_cast<DrawingAction*>(c))
	{
		CFigure* f6 = pManager->GetfigSelectedC();
		f6->Undocolordraw(pManager);
	}
	if (dynamic_cast<FillingAction*>(c))
	{
		CFigure* f = pManager->GetfigSelectedC();
		f->Undocolor(pManager);
	}
	if (dynamic_cast <MoveAction*>(c))
	{
		CFigure* f1 = pManager->GetfigselectedM();
		f1->UndoMove(pManager);
	}
	if (dynamic_cast<delete_action*>(c))
	{

	}
	pManager->AddRedoAction(c);
}

void UndoAction::Execute()
{
	ReadActionParameters();

}