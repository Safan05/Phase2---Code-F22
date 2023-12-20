#include "PlayRecAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
PlayRecAction::PlayRecAction(ApplicationManager* pApp):Action(pApp)
{
}

void PlayRecAction::Execute()
{
	pManager->SetIsPlay(true);
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" Playing Recording ");

	//pManager->Clearall();
	//pOut->ClearDrawArea();
	//for (int i = 0; i <pManager->GetActionCount(); i++) 
	//{
	//	pManager->GetActionList()[i]->Execute();
	//}
	this->UpdateRECInterface();
	pManager->SetIsPlay(false);
	for (int i = 0; i < pManager->GetActionCount(); i++)
	{
		delete pManager->GetActionList()[i];
		pManager->GetActionList()[i] = NULL;
	}
}

void PlayRecAction::UpdateRECInterface()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	for (int i = 0; i < pManager->GetActionCount(); i++) {
		if (pManager->GetRECFigList()[i] != NULL )
			pManager->GetRECFigList()[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
		
}

void PlayRecAction::ReadActionParameters()
{}
