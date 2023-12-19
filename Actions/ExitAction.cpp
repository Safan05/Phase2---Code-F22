#include "ExitAction.h"
#include "ClearAllAction.h"






ExitAction::ExitAction(ApplicationManager* pApp):Action(pApp)
{
}

void ExitAction::Execute()
{
	ClearAllAction* c1 = new ClearAllAction(pManager);
	c1->Execute();
}

void ExitAction::ReadActionParameters()
{
}
