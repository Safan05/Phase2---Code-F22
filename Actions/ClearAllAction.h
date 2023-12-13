#pragma once
#include "Action.h"
class ClearAllAction : public Action
{
public:
	ClearAllAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

