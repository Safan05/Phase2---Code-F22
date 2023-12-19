#pragma once
#include "Action.h"
class ToDrawAction :
    public Action
{
public:
    ToDrawAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
};

