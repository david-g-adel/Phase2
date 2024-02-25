#include "CardEleven.h"
bool CardEleven::isOwned = false;
Player* CardEleven::Owner = NULL;
int CardEleven::cardPrice_11 = 0;
int CardEleven::fees_11 = 0;
CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;
}
CardEleven::CardEleven(const CellPosition& pos, int price, int fees) : Card(pos)
{
	cardNumber = 11;
}
CardEleven::CardEleven() : Card()
{
	cardNumber = 11;
}
void CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (cardPrice_11 == 0)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("New CardEleven:Enter Card price ");
		int p = pIn->GetInteger(pOut);
		if (p > 0)
		{
			cardPrice_11 = p;
		}
		pOut->PrintMessage("New CardEleven:Enter card fee ");
		int f = pIn->GetInteger(pOut);
		if (f > 0)
		{
			fees_11 = f;
		}
		pOut->ClearStatusBar();

	}
}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
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
		if (pPlayer->GetWallet() > cardPrice_11)
		{

			int w = (pPlayer->GetWallet()) - cardPrice_11;
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
		pPlayer->SetWallet(pPlayer->GetWallet() - fees_11);
		Owner->SetWallet(Owner->GetWallet() + fees_11);
	}
}
void CardEleven::SetOwner_11(Player* pPlayer)
{
	Owner = pPlayer;
}
CardEleven::~CardEleven()
{

}
Card* CardEleven::GetCopy()
{
	return new CardEleven(position, cardPrice_11, fees_11);
}
void CardEleven::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		if (firstCardInitialized == true)
		{
			OutFile << cardNumber << " " << position.GetCellNum() << " " << cardPrice_11 << " " << fees_11 << endl;
			firstCardInitialized == false;
		}
		else OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}
void CardEleven::Load(ifstream& Infile)
{
	if (firstCardInitialized == true)
	{
		int cell = 0;
		Infile >> cell >> cardPrice_11 >> fees_11;
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
bool CardEleven::IsOverlapping(GameObject* newObj)
{
	return false;
}