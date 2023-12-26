#include "UndoAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp){
}
void UndoAction::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetUndoCount() > 0) { //checking if there is undo actions to do
		CFigure* undo = pManager->GetUndo()[pManager->GetUndoCount() - 1];
		CFigure* in_list = pManager->GetFigBy_id(undo->GetID());
		if (in_list != NULL) { //undo for actions excluding delete
			CFigure* F = in_list->copy();
			pManager->AddRedo(F);
		}
		else { //undo for delete action 
			CFigure* z = undo->copy();
			z->setID(undo->GetID());
			z->Sethidden(1); //hidden here is just a flag as if it is seen in redo it deletes the figure
			pManager->AddRedo(z);
		}
		if (!undo->Ishidden()) { //not doing an undo for add figure
			if (undo != NULL) { //undo is not null just a safety checker to use copy or not
				CFigure* x = undo->copy();
				x->SetSelected(0);
				pManager->replacefig(in_list,x);
				UI.FillColor = x->get_color();
				if (pManager->GetIsRec()) //record
				{
					CFigure* d1 = x->copy();
					d1->setID(x->GetID());
					pManager->AddRECFig(d1);
				}
			}
			else
			in_list = undo;
			delete undo;
			undo = NULL;
			delete in_list;
			in_list = NULL;
		}
		else { //undo for add figure action
			if (pManager->GetIsRec()) { // record
				CFigure* d1 = in_list->copy();
				d1->setID(in_list->GetID());
				d1->Sethidden(1);
				pManager->AddRECFig(d1);
			}
			pManager->deletefig(in_list);
		}
		pManager->decrementUndoCount(); //to decrease undo count by 1
	}
	else
		pOut->PrintMessage("No more actions to Undo");
}
void UndoAction::ReadActionParameters(){}