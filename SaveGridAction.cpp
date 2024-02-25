#include "SaveGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "GameObject.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp)
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter File Name");
	OutputFile=pIn->GetSrting(pOut);
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	ofstream OutputFile(OutputFile);
	OutputFile << pGrid->LadderCount() << endl;
	//for (int i = 0;i < pGrid->LadderCount();i++)
	{
		pGrid->SaveAll(OutputFile, ObjectLadder);
	}
	OutputFile << pGrid->SnakeCount() << endl;
	//for (int i = 0;i < pGrid->SnakeCount();i++)
	{
		pGrid->SaveAll(OutputFile, ObjectSnake);
	}
	OutputFile << pGrid->CardCount() << endl;
	//for (int i = 0;i < pGrid->CardCount();i++)
	{
		pGrid->SaveAll(OutputFile, ObjectCard);
	}
	OutputFile.close();
	pOut->PrintMessage("Grid Saved Succesfully!");

}


SaveGridAction::~SaveGridAction()
{

}