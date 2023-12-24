#include "SaveAction.h"
#include<fstream>
#include "..\GUI\UI_Info.h"
#include "..\GUI\input.h"
#include "..\GUI\output.h"
#include "..\ApplicationManager.h"
#include<iostream>
#include<string>
#include <mmsystem.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include "VoiceAction.h"
#pragma comment (lib, "Winmm.lib")
using namespace std;
SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
	if (VoiceAction::voice)
		PlaySound(TEXT("voice\\save graph.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Enter the file name");
	FileName = pIn->GetString(pOut);
	pOut->PrintMessage("The File's name is " + FileName);
}

void SaveAction::Execute()
{
	
	ReadActionParameters();
	ofstream Out;
	Out.open(FileName, ios::out);
	if (UI.DrawColor == RED) Out << "RED\t";
	else if (UI.DrawColor == ORANGE) Out << "ORANGE\t";
	else if (UI.DrawColor == BLUE) Out << "BLUE\t";
	else if (UI.DrawColor == GREEN) Out << "GREEN\t";
	else if (UI.DrawColor == YELLOW) Out << "YELLOW\t";
	else if (UI.DrawColor == BLACK) Out << "BLACK\t";
	if (UI.FillColor == RED) Out << "RED\n";
	else if (UI.FillColor == ORANGE) Out << "ORANGE\n";
	else if (UI.FillColor == BLUE) Out << "BLUE\n";
	else if (UI.FillColor == GREEN) Out << "GREEN\n";
	else if (UI.FillColor == YELLOW) Out << "YELLOW\n";
	else if (UI.FillColor == BLACK) Out << "BLACK\n";
	else if (UI.FillColor == Transparent) Out << "TRANSPARENT\n";
	Out << pManager->GetFigCount() << endl;
	pManager->SaveAll(Out);
	Out.close();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Graph is saved successfully");
}
