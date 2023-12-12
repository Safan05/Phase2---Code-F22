#include "Action.h"
#include "StopRecAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StopRecAction::StopRecAction(ApplicationManager* pApp) :Action(pApp)
{}

void StopRecAction::Execute()
{
	if (pManager->GetIsRec())
	{
		pManager->SetIsRec(false);
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage(" stopped Recording");
	}
}

void StopRecAction::ReadActionParameters()
{}
