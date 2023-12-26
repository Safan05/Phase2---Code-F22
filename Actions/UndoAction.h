#pragma once
#include "Action.h"
class UndoAction : public Action
{

public:
    UndoAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
};

