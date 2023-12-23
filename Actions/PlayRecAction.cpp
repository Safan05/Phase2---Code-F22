#include "PlayRecAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
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
	this->UpdateRECInterface();
	pOut->PrintMessage(" Finished playing ");

	/*for (int i = 0; i < pManager->GetRecFIGCount(); i++)
	{
		delete pManager->GetRECFigList()[i];
		pManager->GetRECFigList()[i] = NULL;
	}*/
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
			pOut->ClearDrawArea();
			for (int j = 0; j < i+1; j++) {

				if (pManager->GetRECFigList()[j] != NULL && !(pManager->GetRECFigList()[j]->Ishidden())) {
					pManager->GetRECFigList()[j]->Draw(pOut);		//Call Draw function (virtual member fn)
				}
			}
		}
	}
		
}

void PlayRecAction::CompareID(int id, int index)
{
	int i = index - 1;
	bool flag = true;
	while (i >= 0&&flag) 
	{
		if (pManager->GetRECFigList()[i] != NULL) {
			if (pManager->GetRECFigList()[i]->GetID() == id) {
				pManager->GetRECFigList()[i]->Sethidden(1);
				delete pManager->GetRECFigList()[i];
				pManager->GetRECFigList()[i] = NULL;
				flag=false;
			}
		}
		i--;
	}
	i = index - 1;
	flag = true;
	while(i>=0&&flag) {
		if (pManager->GetRECFigList()[i] != NULL)
			if (pManager->GetRECFigList()[i]->IsSelected() == 1) {
				pManager->GetRECFigList()[i]->SetSelected(0);
				flag=false;
			}
		i--;
	}
}

void PlayRecAction::ReadActionParameters()
{}
