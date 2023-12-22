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
		CFigure::LastID--;
		CFigure* f = pManager->GetRECFigList()[i];
		if (f != NULL) 
		{
			this->CompareID(f, i);
			Sleep(1000);
			pManager->GetRECFigList()[i]->Draw(pOut);
		}
	}
		
}

void PlayRecAction::CompareID(CFigure* f, int index)
{
	int i = index - 1;
	while (i >= 0) 
	{
		if (pManager->GetRECFigList()[i] != NULL) {
			if (pManager->GetRECFigList()[i]->GetID() == f->GetID()) {
				delete pManager->GetRECFigList()[i];
				pManager->GetRECFigList()[i] = NULL;
				break;
			}
		}
		i--;
	}

}

void PlayRecAction::ReadActionParameters()
{}
