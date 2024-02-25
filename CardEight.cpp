#include "CardEight.h"
CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;

}
CardEight::CardEight() : Card()
{
	cardNumber = 8;
}
void CardEight::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardEight:Enter Fine amount ");
	amount = pIn->GetInteger(pOut);


}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("(1)pay  (2)stay ");
	int choice = pIn->GetInteger(pOut);
	if (choice == 2)
	{
		pPlayer->setstopped(3);
	}
	else
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - amount);
	}
}
CardEight::~CardEight()
{

}
Card* CardEight::GetCopy()
{
	return new CardEight(position);
}
void CardEight::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << cardNumber << " " << position.GetCellNum() <<amount<< endl;

	}
}
void CardEight::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell>>amount;
	position = cell;
	
}
bool CardEight::IsOverlapping(GameObject* newObj)
{
	return false;
}