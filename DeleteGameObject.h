#pragma once
#include "Action.h"
#include "CellPosition.h"
class DeleteGameObject :
    public Action
{
private:
    CellPosition CellSelected;
public:
    DeleteGameObject(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};