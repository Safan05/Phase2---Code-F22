#include "ClearAllAction.h"
#include"..\ApplicationManager.h"
#include"Action.h"
#include "..\GUI\UI_Info.h"
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
	//for (int i = 0; i < pManager->GetRecFIGCount(); i++) {
		//delete  pManager->GetRECFigList()[i];
		//pManager->GetRECFigList()[i] = NULL;
	//}
	
}
