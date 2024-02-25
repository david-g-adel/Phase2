#pragma once
#include "Action.h"
class Paste :
    public Action
{    Card* Pasted;
CellPosition CellPosPaste;
public:
    Paste(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};