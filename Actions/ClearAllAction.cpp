#include "ClearAllAction.h"
#include"..\ApplicationManager.h"
#include"Action.h"
#include "..\GUI\UI_Info.h"
#include "..\Figures\CCirc.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp):Action(pApp)
{}

void ClearAllAction::ReadActionParameters()
{}

void ClearAllAction::Execute()
{
	pManager->Clearall();
	UI.DrawColor = BLUE;
	UI.FillColor = Transparent;
	UI.IsFilledNext = 0;
	if(pManager->GetIsRec())
	{
		CCirc* c1 = new CCirc;
		c1->setID(600);
		pManager->AddRECFig(c1);
		
	}
	else
	for (int i = 0; i < pManager->GetRecFIGCount(); i++)
	{
		if (pManager->GetRECFigList()[i] != NULL&& pManager->GetRECFigList()[i]->Ishidden()==0)
		{
			CFigure* d1 = pManager->GetRECFigList()[i]->copy();
			if (pManager->GetRECFigList()[i]->IsSelected() == 1) {
				pManager->set_selected(d1);
			}
			pManager->AddFigure(d1);

		}
		delete  pManager->GetRECFigList()[i];
		pManager->GetRECFigList()[i] = NULL;
	}
	for (int i = 0; i < pManager->GetUndoCount(); i++)
	{
		if (pManager->GetUndoAction()[i] != NULL)
		{
			delete pManager->GetUndoAction()[i];
			pManager->GetUndoAction()[i] = NULL;
		}
	}
	for (int i = 0; i < pManager->GetRedoCount(); i++)
	{
		if (pManager->GetRedoAction()[i] != NULL)
		{
			delete pManager->GetRedoAction()[i];
			pManager->GetRedoAction()[i] = NULL;
		}

	}
	for (int i = 0; i < pManager->Getredofigcount(); i++)
	{
		if (pManager->GetRedofig()[i] != NULL)
		{
			delete pManager->GetRedofig()[i];
			pManager->GetRedofig()[i] = NULL;
		}

	}
}
