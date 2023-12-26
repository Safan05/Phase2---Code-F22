#pragma once
#include "Action.h"
class RedoAction : public Action
{

public:
    RedoAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
};
