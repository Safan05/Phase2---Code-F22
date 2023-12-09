#include "SaveAction.h"
#include<fstream>
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
	FileName = pIn->GetSrting(pOut);
	pOut->PrintMessage("The File's name is " + FileName);
}

void SaveAction::Execute()
{
	
	ReadActionParameters();
	ofstream Out;
	Out.open(FileName, ios::out);
	pManager->SaveAll(Out);
	Out.close();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Graph is saved successfully");
}
