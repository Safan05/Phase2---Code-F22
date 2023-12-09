#include "ActionToPick.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

ActionToPick::ActionToPick(ApplicationManager* pApp) :Action(pApp) 
{}
void ActionToPick::ReadActionParameters() {}
void ActionToPick::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreatePickToolBar();
}