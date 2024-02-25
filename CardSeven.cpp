#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
}
CardSeven::CardSeven() : Card()
{
	cardNumber = 7;
}
void CardSeven::ReadCardParameters(Grid* pGrid)
{

}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);  //Call Apply() of the base class Card to print the message that you reached this card number
	int PlayerOnCardCellNum = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum();
	int LeastCellNumDiff = 9999;
	Player* pLeastPosDiff;
	bool valid = false;
	for (int i = 0; i < 3; i++)
	{

		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() > PlayerOnCardCellNum && ((pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() - PlayerOnCardCellNum) < LeastCellNumDiff))
		{
			valid = true;
			LeastCellNumDiff = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() - PlayerOnCardCellNum;
			pLeastPosDiff = pGrid->GetCurrentPlayer();
		}


	}
	if (valid == true)
	{
		pLeastPosDiff->MoveToCell(pGrid, 1);

	}
	pGrid->AdvanceCurrentPlayer();


}
CardSeven::~CardSeven()
{
}
Card* CardSeven::GetCopy()
{
	return new CardSeven(position);
}
void CardSeven::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() <<endl;

	}
}
void CardSeven::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell;
	position = cell;
}
bool CardSeven::IsOverlapping(GameObject* newObj)
{
	return false;
}