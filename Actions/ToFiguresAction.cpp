#include "ToFiguresAction.h"
#include "Action.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ToFiguresAction::ToFiguresAction(ApplicationManager* pApp):Action(pApp)
{
}

void ToFiguresAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateFigureToolBar();
}

void ToFiguresAction::ReadActionParameters()
{
}
