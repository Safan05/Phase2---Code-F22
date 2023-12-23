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
		delete  pManager->GetRECFigList()[i];
		pManager->GetRECFigList()[i] = NULL;
	}
}
