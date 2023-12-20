#pragma once
#include "Action.h"
class ToFiguresAction :
    public Action
{
public:
    ToFiguresAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
};

