#pragma once
#include "Action.h"
class VoiceAction : public Action
{
private:
public:
	static bool voice;
	VoiceAction(ApplicationManager* pApp);//constructor
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
};