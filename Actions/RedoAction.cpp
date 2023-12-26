#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {
}
void RedoAction::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRedoCount() > 0) {
		CFigure* redo = pManager->GetRedo()[pManager->GetRedoCount() - 1];
		CFigure* in_list = pManager->GetFigBy_id(redo->GetID());
		if (in_list != NULL) {
			CFigure* F = in_list->copy();
			pManager->AddUndo(F);
		}
		else {
			CFigure* z = redo->copy();
			z->setID(redo->GetID());
			z->Sethidden(1);
			pManager->AddUndo(z);
		}
		if (!redo->Ishidden()) {
			if (redo != NULL) {
				CFigure* x = redo->copy();
				x->SetSelected(0);
				pManager->replacefig(in_list, x);
				UI.FillColor = x->get_color();
				if (pManager->GetIsRec()) //record
				{
					CFigure* d1 = x->copy();
					d1->setID(x->GetID());
					pManager->AddRECFig(d1);
				}
			}
			else
				in_list = redo;
			delete redo;
			redo = NULL;
			delete in_list;
			in_list = NULL;
		}
		else {
			if (pManager->GetIsRec()) { // record
				CFigure* d1 = in_list->copy();
				d1->setID(in_list->GetID());
				d1->Sethidden(1);
				pManager->AddRECFig(d1);
			}
			pManager->deletefig(in_list);
		}
		pManager->decrementRedoCount();
	}
	else
		pOut->PrintMessage("No more actions to Redo");
}
void RedoAction::ReadActionParameters() {}