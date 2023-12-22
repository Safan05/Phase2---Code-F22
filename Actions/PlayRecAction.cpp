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
	//for (int i = 0; i <pManager->GetActionCount(); i++) 
	//{
	//	pManager->GetActionList()[i]->Execute();
	//}
	this->UpdateRECInterface();
	pOut->PrintMessage(" Finished playing ");

	//for (int i = 0; i < pManager->GetRecFIGCount(); i++)
	//{
	//	delete pManager->GetRECFigList()[i];
		//pManager->GetRECFigList()[i] = NULL;
	//}
	pManager->unhide();
}

void PlayRecAction::UpdateRECInterface()
{
	Output* pOut = pManager->GetOutput();
	//pOut->ClearDrawArea();
	for (int i = 0; i < pManager->GetRecFIGCount(); i++) 
	{
		
		if (pManager->GetRECFigList()[i] != NULL) 
		{
			this->CompareID(pManager->GetRECFigList()[i]->GetID(), i);
			Sleep(1000);
			pManager->GetRECFigList()[i]->Draw(pOut);
		}
	}
		
}

void PlayRecAction::CompareID(int id, int index)
{
	int i = index - 1;
	while (i >= 0) 
	{
		if(pManager->GetRECFigList()[i]==NULL)
		if (pManager->GetRECFigList()[i]->GetID() == id) {
			 pManager->GetRECFigList()[i]->Sethidden(true);
			 break;
		}
		i--;
	}

}

void PlayRecAction::ReadActionParameters()
{}
