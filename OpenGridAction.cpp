#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
using namespace std;
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp)
{

}


void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter File Name: ");
	InputFile = pIn->GetSrting(pOut);
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	ifstream InputFile(InputFile);
	if (InputFile.is_open() == false)
	{
		pGrid->PrintMessageAndWait("Cannot Load File!!");
		return;
	}
	pGrid->ClearAll();
	for (int i = 0;i < 4;i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pPlayer->Restart(pGrid);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrPlayer(0);
	int numOfLadders = 0;
	int numOfSnakes = 0;
	int numOfCards = 0;
	GameObject*obj;
	InputFile >> numOfLadders;
	for (int i = 0;i < numOfLadders;i++)
	{
		obj = new Ladder;
		obj->Load(InputFile);
		pGrid->AddObjectToCell(obj);
	}
	InputFile >> numOfSnakes;
	for (int i = 0;i < numOfSnakes;i++)
	{
		obj = new Snake;
		obj->Load(InputFile);
		pGrid->AddObjectToCell(obj);
	}
	InputFile >> numOfCards;
	for (int i = 0;i < numOfCards;i++)
	{
		int cardNumber = 0;
		InputFile >> cardNumber;
		switch (cardNumber)
		{
		case 1:
			obj = new CardOne;
			obj->Load(InputFile);
			pGrid->AddObjectToCell(obj);
			break;
		case 2:
			obj = new CardTwo;
			break;
		case 3:
			obj = new CardThree;
			obj->Load(InputFile);
			pGrid->AddObjectToCell(obj);
			break;
		case 4:
			obj = new CardFour;
			obj->Load(InputFile);
			pGrid->AddObjectToCell(obj);
			break;
		case 5:
			obj = new CardFive();
			obj->Load(InputFile);
			pGrid->AddObjectToCell(obj);
			break;
		case 6:
			obj = new CardSix();
			obj->Load(InputFile);
			pGrid->AddObjectToCell(obj);
			break;
		case 7:
			obj = new CardSeven();
			obj->Load(InputFile);
			pGrid->AddObjectToCell(obj);
			break;

		}
	}
	InputFile.close();
}
						

OpenGridAction::~OpenGridAction()
{

}