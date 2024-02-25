#include "CardTwo.h"
#include"Ladder.h"

CardTwo::CardTwo(const CellPosition& pos) :Card(pos)
{
	cardNumber = 2;
}
CardTwo::CardTwo() : Card()
{
	cardNumber = 2;
}
void CardTwo::ReadCardParameters(Grid* pGrid)
{

}



void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* In = pGrid->GetInput();
	Output* Out = pGrid->GetOutput();
	Ladder* lad = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	if (lad == NULL)
	{
		int x, y;
		Out->PrintMessage("no ladder click to continue");
		In->GetPointClicked(x, y);
		Out->ClearStatusBar();

	}
	else
	{

		int num = lad->GetPosition().GetCellNum();
		CellPosition C = CellPosition(num);
		pPlayer->MoveToCell(pGrid, C);

	}

}
CardTwo::~CardTwo()
{

}
Card* CardTwo::GetCopy()
{
	return new CardTwo(position);
}
void CardTwo::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() <<endl;

	}
}
void CardTwo::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell;
	position = cell;
}
bool CardTwo::IsOverlapping(GameObject* newObj)
{
	return false;
}
