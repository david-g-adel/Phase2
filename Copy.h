#pragma once
#include "Action.h"
class Copy :
    public Action
{
protected:
    Card* Copied;
    CellPosition CellPos;
    

public:
    Copy(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};

