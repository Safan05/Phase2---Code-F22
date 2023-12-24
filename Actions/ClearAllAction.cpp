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
	UI.FillColor = GREEN;
	UI.IsFilledNext = 0;
	if(pManager->GetIsRec())
	{
		CCirc* c1 = new CCirc;
		c1->setID(140);
		pManager->AddRECFig(c1);
		
	}
	else
	for (int i = 0; i < pManager->GetRecFIGCount(); i++)
	{
		if (pManager->GetRECFigList()[i] != NULL) {
			CFigure* d1 = pManager->GetRECFigList()[i]->copy();
			if (pManager->GetRECFigList()[i]->IsSelected() == 1) {
				pManager->AddFigure(d1);
				pManager->set_selected(d1);
			}
			else
				pManager->AddFigure(d1);
			delete  pManager->GetRECFigList()[i];
			pManager->GetRECFigList()[i] = NULL;
		}
	}
}
