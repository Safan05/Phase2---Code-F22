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
	for (int i = 0; i < pManager->GetActionCount(); i++) {
		delete  pManager->GetActionList()[i];
		pManager->GetActionList()[i] = NULL;
	}
	
}
