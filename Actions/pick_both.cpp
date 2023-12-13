#include "pick_both.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CHexa.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTri.h"
#include "..\Figures\CSquare.h"

pick_both::pick_both(ApplicationManager* pApp) :Action(pApp) {};//constructor

//Reads parameters required for action to execute (code depends on action type)
void pick_both::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
};

//Execute action (code depends on action type)
void pick_both::Execute() {
	
}