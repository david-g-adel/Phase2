#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
}
CardFive::CardFive() : Card()
{
	cardNumber = 5;
}
void CardFive::ReadCardParameters(Grid* pGrid)
{


}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	int n = (pPlayer->GetCell()->GetCellPosition().GetCellNum()) - (pPlayer->getjustRolledDiceNum());
	CellPosition C = CellPosition(n);
	pPlayer->MoveToCell(pGrid, C);

}
CardFive::~CardFive()
{

}
Card* CardFive::GetCopy()
{
	return new CardFive(position);
}
void CardFive::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << endl;

	}
}
void CardFive::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell;
	position = cell;
}
bool CardFive::IsOverlapping(GameObject* newObj)
{
	return false;
}