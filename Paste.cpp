#include "Paste.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"
Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{

}
void Paste::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Select the Cell you Want to Paste on");
	CellPosPaste = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void Paste::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Cell* pCell = pGrid->GetCellFromCellPos(CellPosPaste);
	Pasted = pGrid->GetClipboard();
	if (Pasted != NULL)
	{
		Pasted->SetPosition(CellPosPaste);
		pGrid->AddObjectToCell(Pasted);
		pOut->PrintMessage("Card Pasted Successfully.");
	}
	else pGrid->PrintMessageAndWait("Cannot Paste!!");
}
