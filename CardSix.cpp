#include "CardSix.h"
#include "CellPosition.h"
CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}
CardSix::CardSix(CellPosition& pos, int cell):Card(pos)
{
	cardNumber = 6;
}
CardSix::CardSix() : Card()
{
	cardNumber = 6;
}
void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardSix: Enter cell number: ");
	int value = pIn->GetInteger(pOut);
	if (value >= 0 && value < 100)
	{
		cellnum = value;
	}

}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition C = CellPosition(cellnum);

	pPlayer->MoveToCell(pGrid, C);

}
CardSix::~CardSix()
{

}
Card* CardSix::GetCopy()
{
	return new CardSix(position, cellnum);
}
void CardSix::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << cellnum<<endl;

	}
}
void CardSix::Load(ifstream& Infile)
{
	int cell = 0;
	int toCell = 0;
	Infile >> cell>>toCell;
	position = cell;
	cellnum = toCell;
}
bool CardSix::IsOverlapping(GameObject* newObj)
{
	return false;
}
