#include "ActionToplay.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
ActionToplay::ActionToplay(ApplicationManager* pApp) :Action(pApp)
{}
void ActionToplay::ReadActionParameters() {}
void ActionToplay::Execute()
{
	Output* pOut = pManager->GetOutput();
	pManager->unhide();
	pOut->CreatePlayToolBar();
}