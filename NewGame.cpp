#include "NewGame.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{

}
void NewGame::ReadActionParameters()
{

}
void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	for (int i = 0;i < 4;i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pPlayer->Restart(pGrid);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrPlayer(0);
}


