#include "PlayRecAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
PlayRecAction::PlayRecAction(ApplicationManager* pApp):Action(pApp)
{
}

void PlayRecAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Playing Recording ");

	//pManager->Clearall();
	pOut->ClearDrawArea();
	for (int i = 0; i <pManager->GetActionCount(); i++) 
	{
		pManager->GetActionList()[i]->Execute();
	}
}

void PlayRecAction::ReadActionParameters()
{}
