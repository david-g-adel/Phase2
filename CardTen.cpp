#include "CardTen.h"
bool CardTen::isOwned = false;
Player* CardTen::Owner = NULL;
int CardTen::cardPrice_10 = 0;
int CardTen::fees_10 = 0;
CardTen::CardTen(const CellPosition& pos) : Card(pos)
{
	cardNumber = 10;
}
CardTen::CardTen(const CellPosition& pos, int price, int fees) : Card(pos)
{
	cardNumber = 10;
}
CardTen::CardTen() : Card()
{
	cardNumber = 10;
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
	if (cardPrice_10 == 0)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("New CardTen:Enter Card price ");
		int p = pIn->GetInteger(pOut);
		if (p > 0)
		{
			cardPrice_10 = p;
		}
		pOut->PrintMessage("New CardTen:Enter card fee ");
		int f = pIn->GetInteger(pOut);
		if (f > 0)
		{
			fees_10 = f;
		}
		pOut->ClearStatusBar();
		firstCardInitialized = true;
	}


}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int ans = 0;
	if (isOwned == false)
	{

		pOut->PrintMessage("To buy this station press (1): ");
		ans = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
		ans = 1;
	}
	if (ans == 1)  //process of purchase
	{
		if (pPlayer->GetWallet() > cardPrice_10)
		{

			int w = (pPlayer->GetWallet()) - cardPrice_10;
			pPlayer->SetWallet(w);
			pGrid->PrintMessageAndWait("Congratulations!! You are now the owner of the station ");
			Owner = pPlayer;
			isOwned = true;
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->PrintMessageAndWait("You dont have enough money!!");
		}
	}

	if (pPlayer != Owner)   //passage of a player on station
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - fees_10);
		Owner->SetWallet(Owner->GetWallet() + fees_10);
	}

}
void CardTen::SetOwner_10(Player* pPlayer)
{
	Owner = pPlayer;
}
CardTen::~CardTen()
{

}
Card* CardTen::GetCopy()
{
	return new CardTen(position, cardPrice_10, fees_10);
}
void CardTen::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		if (firstCardInitialized == true)
		{
			OutFile << cardNumber << " " << position.GetCellNum() << " " << cardPrice_10 << " " << fees_10 << endl;
			firstCardInitialized == false;
		}
		else OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}
void CardTen::Load(ifstream& Infile)
{
	if (firstCardInitialized == true)
	{
		int cell = 0;
		Infile >> cell >> cardPrice_10 >> fees_10;
		position = cell;
		firstCardInitialized == false;

	}
	else
	{
		int cell = 0;
		Infile >> cell;
		position = cell;
	}
}
bool CardTen::IsOverlapping(GameObject* newObj)
{
	return false;
}