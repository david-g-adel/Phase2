#pragma once
#include "Action.h"
class InputDiceValue :
    public Action
{
private:
    int DiceValue;
public:
	InputDiceValue(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();

	virtual ~InputDiceValue(); // A Virtual Destructor
};

