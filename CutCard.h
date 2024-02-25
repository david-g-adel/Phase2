#pragma once
#include "Action.h"
#include"Copy.h"
class CutCard :public Copy
{

public:
	CutCard(ApplicationManager* pAct);
	virtual void ReadActionParameters();
	virtual void Execute();
};

