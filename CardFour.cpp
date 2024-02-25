#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) :Card(pos)
{
	cardNumber = 4;
}
CardFour::CardFour() : Card()
{
	cardNumber = 4;
}
void CardFour::ReadCardParameters(Grid* pGrid)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->setstopped(1);
}
CardFour::~CardFour()
{

}
Card* CardFour::GetCopy()
{
	return new CardFour(position);
}
void CardFour::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() <<endl;

	}
}
void CardFour::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell;
	position = cell;
}
bool CardFour::IsOverlapping(GameObject* newObj)
{
	return false;
}
