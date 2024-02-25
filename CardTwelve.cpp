/*#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos) :Card(pos), CardNine(pos), CardTen(pos), CardEleven(pos)
{
	Card::cardNumber = 12;
}
CardTwelve::CardTwelve() : Card(), CardNine(), CardTen(), CardEleven()
{
	Card::cardNumber = 12;
}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Player* minPlayer = LeastWallet(pGrid, pPlayer);

	Card* MaxOwner = MaxStation(pGrid, pPlayer);
	if (MaxOwner != NULL && MaxOwner->GetCardNumber() == 9)
	{
		CardNine::SetOwner_9(minPlayer);
	}
	if (MaxOwner != NULL && MaxOwner->GetCardNumber() == 10)
	{
		CardTen::SetOwner_10(minPlayer);
	}
	if (MaxOwner != NULL && MaxOwner->GetCardNumber() == 11)
	{
		CardEleven::SetOwner_11(minPlayer);
	}
	pGrid->AdvanceCurrentPlayer();
}
Player* CardTwelve::LeastWallet(Grid* pGrid, Player* pPlayer)
{
	pGrid->AdvanceCurrentPlayer();
	int leastwalletamount = pGrid->GetCurrentPlayer()->GetWallet();
	Player* leastplayer = pGrid->GetCurrentPlayer();

	for (int i = 0; i < 2; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetWallet() < leastwalletamount)
		{
			leastwalletamount = pGrid->GetCurrentPlayer()->GetWallet();
			leastplayer = pGrid->GetCurrentPlayer();
		}

	}
	return leastplayer;
}
Card* CardTwelve::MaxStation(Grid* pGrid, Player* pPlayer)
{
	int maxcard = 0;
	int maxprice = 0;
	Card* Ownerm = NULL;

	if (CardNine::Owner != NULL && CardNine::Owner->GetPlayerNum() == pPlayer->GetPlayerNum() && CardNine::cardPrice_9 > maxprice)
	{
		maxprice = CardNine::cardPrice_9;
		maxcard = 9;
		Ownerm = new CardNine(pPlayer->GetCell()->GetCellPosition());

	}
	if (CardTen::Owner != NULL && CardTen::Owner->GetPlayerNum() == pPlayer->GetPlayerNum() && CardTen::cardPrice_10 > maxprice)
	{
		maxprice = CardTen::cardPrice_10;
		maxcard = 10;
		Ownerm = new CardTen(pPlayer->GetCell()->GetCellPosition());
	}
	if (CardEleven::Owner != NULL && CardEleven::Owner->GetPlayerNum() == pPlayer->GetPlayerNum() && CardEleven::cardPrice_11 > maxprice)
	{
		maxprice = CardEleven::cardPrice_11;
		maxcard = 11;
		Ownerm = new CardEleven(pPlayer->GetCell()->GetCellPosition());
	}
	return Ownerm;

}

CardTwelve::~CardTwelve()
{

}
Card* CardTwelve::GetCopy()
{
	return new CardTwelve(Card::position);
}
void CardTwelve::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectCard)
	{
		OutFile << Card::cardNumber << " " << Card::position.GetCellNum() << endl;

	}
}
void CardTwelve::Load(ifstream& Infile)
{
	int cell = 0;
	Infile >> cell;
	Card::position = cell;
}
bool CardTwelve::IsOverlapping(GameObject* newObj)
{
	return false;
}*/