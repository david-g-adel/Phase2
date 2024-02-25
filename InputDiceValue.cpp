#include "InputDiceValue.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include"Player.h"
InputDiceValue::InputDiceValue(ApplicationManager* pApp):Action(pApp)// A Constructor
{

}

void InputDiceValue::ReadActionParameters() // Reads InputDiceValue action parameters (dicevalue)
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter Dice Value: ");

	int dice = pIn->GetInteger(pOut);
	if (dice > 0 && dice < 7)
	{
		validation = true;
		DiceValue = dice;
		return;
	}
	else
	{
		pGrid->PrintMessageAndWait("Dice Value is Invalid!");
		return;
	}
}
void InputDiceValue::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (validation==true)
	{
		pOut->PrintMessage("You Got " + to_string(DiceValue));
		Player* P = pGrid->GetCurrentPlayer();
		//Move the currentPlayer using function Move of class player
		P->Move(pGrid, DiceValue);
		//Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	else return;
}

InputDiceValue::~InputDiceValue() // A Virtual Destructor
{}