#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) :Card(pos)
{
	cardNumber = 3;
}
CardThree::CardThree() :Card()
{
	cardNumber = 3;
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
 }

void CardThree::Apply(Grid* pGrid, Player* pPlayer) 
{
	Card::Apply(pGrid, pPlayer);
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
	}
	pPlayer->SetTurnCount((pPlayer->GetTurnCount()) - 1);
	
 }
CardThree::~CardThree()
{

}
Card* CardThree::GetCopy()
{
	return new CardThree(position);
}
void CardThree::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() <<endl;

	}
}
void CardThree::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell;
	position = cell;
}
bool CardThree::IsOverlapping(GameObject* newObj)
{
	return false;
}