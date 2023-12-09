#include "SaveAction.h"
#include<fstream>
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\ApplicationManager.h"
#include<iostream>
#include<string>
using namespace std;
SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter the file name");
	FileName = pIn->GetSrting(pOut);
	pOut->PrintMessage("The File's name is " + FileName);
}

void SaveAction::Execute()
{
	
	ReadActionParameters();
	ofstream Out;
	Out.open(FileName, ios::out);
	Out << pManager->GetFigCount() << endl;
	pManager->SaveAll(Out);
	Out.close();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Graph is saved successfully");
}
