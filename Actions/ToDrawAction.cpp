#include "ToDrawAction.h"

#include "Action.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToDrawAction::ToDrawAction(ApplicationManager* pApp):Action(pApp)
{
}

void ToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
}

void ToDrawAction::ReadActionParameters()
{
}
