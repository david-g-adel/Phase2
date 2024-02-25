#include "CutCard.h"
#include "Copy.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"
CutCard::CutCard(ApplicationManager* pAct) :Copy(pAct)
{
}
void CutCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Select The Card You Want To Cut..");
	CellPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void CutCard::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Copy::Execute();
	pGrid->RemoveObjectFromCell(CellPos);
}