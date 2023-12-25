#include "PlayRecAction.h"
#include "ClearAllAction.h"
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
	if (pManager->GetIsRec()) 
	{
		pOut->PrintMessage(" Stop Recording First ");
	}
	else {
		pOut->PrintMessage(" Playing Recording ");
		pManager->Clearall();
		Sleep(500);
		this->UpdateRECInterface();
		Sleep(1000);
		pOut->PrintMessage(" Finished playing ");
		Sleep(1000);
		ClearAllAction* c1 = new ClearAllAction(pManager);
		c1->Execute();
	}
}

void PlayRecAction::UpdateRECInterface()
{
	Output* pOut = pManager->GetOutput();
	for (int i = 0; i < pManager->GetRecFIGCount(); i++) 
	{
		if (pManager->GetRECFigList()[i] != NULL)
		{
			this->CompareID(pManager->GetRECFigList()[i]->GetID(), i);
			Sleep(1000);
			pOut->ClearDrawArea();
			if (pManager->GetRECFigList()[i]->GetID() == 600) 
			{
				for (int j = 0; j < i + 1; j++) {

					if (pManager->GetRECFigList()[j] != NULL && !(pManager->GetRECFigList()[j]->Ishidden())) 
					{
						pManager->GetRECFigList()[j]->Sethidden(1);		
						pOut->Updatebuffer();
					}
				}
			}
			else
				for (int j = 0; j < i+1; j++) {

				if (pManager->GetRECFigList()[j] != NULL && !(pManager->GetRECFigList()[j]->Ishidden())) {
					pManager->GetRECFigList()[j]->Draw(pOut);		
					pOut->Updatebuffer();
				}
			}
		}
		pOut->Updatebuffer();
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
