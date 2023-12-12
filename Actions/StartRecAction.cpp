#include "StartRecAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp)
{
}

void StartRecAction::Execute()
{
	if (pManager->GetFigCount() != 0) 
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage(" Not Recording Clear all first");
	}
	else 
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage(" Started recording ");
		pManager->SetIsRec(true);
		
	}
	
}

void StartRecAction::ReadActionParameters()
{}


