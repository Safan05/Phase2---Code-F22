#include "ToPlayAction.h"
#include "Action.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToPlayAction::ToPlayAction(ApplicationManager* pApp):Action(pApp)
{
}

void ToPlayAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pManager->unhide();
	pOut->CreatePlayToolBar();
}

void ToPlayAction::ReadActionParameters()
{
}
