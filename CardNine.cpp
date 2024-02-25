#include "CardNine.h"
bool CardNine::isOwned = false;
Player* CardNine::Owner = NULL;
int CardNine::cardPrice_9 = 0;
int CardNine::fees_9 = 0;

CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;

}
CardNine::CardNine(const CellPosition& pos, int price, int fees) : Card(pos)
{
	cardNumber = 9;
}
CardNine::CardNine() : Card()
{
	cardNumber = 9;
}
void CardNine::ReadCardParameters(Grid* pGrid)
{
	if (cardPrice_9 == 0)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("New CardNine:Enter Card price ");
		int p = pIn->GetInteger(pOut);
		if (p > 0)
		{
			cardPrice_9 = p;
		}
		pOut->PrintMessage("New CardNine:Enter card fee ");
		int f = pIn->GetInteger(pOut);
		if (f > 0)
		{
			fees_9 = f;
		}
		pOut->ClearStatusBar();
		firstCardInitialized = true;
	}

}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
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
		if (pPlayer->GetWallet() > cardPrice_9)
		{

			int w = (pPlayer->GetWallet()) - cardPrice_9;
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
		pPlayer->SetWallet(pPlayer->GetWallet() - fees_9);
		Owner->SetWallet(Owner->GetWallet() + fees_9);
	}


}

void CardNine::SetOwner_9(Player* pPlayer)
{
	Owner = pPlayer;
}
CardNine::~CardNine()
{

}
Card* CardNine::GetCopy()
{
	return new CardNine(position,cardPrice_9,fees_9);
}
void CardNine::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		if (firstCardInitialized==true)
		{
			OutFile << cardNumber << " " << position.GetCellNum() << " " << cardPrice_9 << " " << fees_9 << endl;
			firstCardInitialized == false;
		}
		else OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}
void CardNine::Load(ifstream& Infile)
{
	if (firstCardInitialized == true)
	{
		int cell = 0;
		Infile >> cell >> cardPrice_9 >> fees_9;
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
bool CardNine::IsOverlapping(GameObject* newObj)
{
	return false;
}