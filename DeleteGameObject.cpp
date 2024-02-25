#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteGameObject::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Select The Object You want to Delete ...");
	CellPosition C = pIn->GetCellClicked();
	CellSelected = C;

}
void DeleteGameObject::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	bool removed = pGrid->RemoveObjectFromCell(CellSelected);

	pOut->ClearStatusBar();
}
