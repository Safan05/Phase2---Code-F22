#include "delete_action.h"
#include "selectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
delete_action::delete_action(ApplicationManager* pApp) :Action(pApp) {};//constructor

//Reads parameters required for action to execute (code depends on action type)
void delete_action::ReadActionParameters() {
};

//Execute action (code depends on action type)
void delete_action::Execute() {
	CFigure* f=pManager->Get_selected();
	pManager->deletefig(f);
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
}