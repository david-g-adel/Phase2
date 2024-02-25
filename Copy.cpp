#include "Copy.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"
Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{
}
void Copy::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please Select The Card You Want To Copy..");
	CellPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void Copy::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Cell*pCell = pGrid->GetCellFromCellPos(CellPos);
	if (pCell->HasCard() != NULL)
	{
		Copied = pCell->HasCard()->GetCopy();
		pGrid->SetClipboard(Copied);
			pOut->PrintMessage("Card is in Clipboard..");
	}
	else pGrid->PrintMessageAndWait("Cell has no Card..");
}

