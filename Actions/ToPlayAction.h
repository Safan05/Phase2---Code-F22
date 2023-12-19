#pragma once
#include "Action.h"
class ToPlayAction :
    public Action
{
public:
    ToPlayAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
};

