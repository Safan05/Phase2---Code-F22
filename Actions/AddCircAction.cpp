#include "AddCircAction.h"
#include "..\Figures\CCirc.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <cmath>

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center");

	//Read center and store in point center
	pIn->GetPointClicked(center.x, center.y);
	if (ValidP(center)) {
		pOut->PrintMessage("New Circle: Click at an another point");

		//Read 2nd point and store in point point
		pIn->GetPointClicked(point.x, point.y);
		if (ValidP(point)) {
			if (Valid()) {
				CircGfxInfo.isFilled = false;	//default is not filled
				//get drawing, filling colors and pen width from the interface
				CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
				CircGfxInfo.FillClr = pOut->getCrntFillColor();

				pOut->ClearStatusBar();
			}
			else  pOut->PrintMessage("Invalid, Can't draw in Toolbar");
		}
		else pOut->PrintMessage("Invalid Point, Can't place point here");
	}
	else pOut->PrintMessage("Invalid Point, Can't place point here");
}

bool AddCircAction::Valid()
{
	int a, b, r;
	a = abs(center.x - point.x);
	b = abs(center.y - point.y);
	r = sqrt(a * a + b * b);
	return (((center.y - UI.ToolBarHeight) >= r) && ((UI.height - UI.StatusBarHeight) - center.y >= r));
}

bool AddCircAction::ValidP(Point P)
{
	return (P.y > UI.ToolBarHeight) && (P.y < UI.height - UI.StatusBarHeight);
}

void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (Valid()) {
		//Create a circle with the parameters read from the user
		CCirc* C = new CCirc(center, point, CircGfxInfo);

		//Add the circle to the list of figures
		pManager->AddFigure(C);
	}
}