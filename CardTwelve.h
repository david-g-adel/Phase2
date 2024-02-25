/*#pragma once
#include "Card.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

class CardTwelve : public Card, public CardNine, public CardTen, public CardEleven
{

public:
	CardTwelve(const CellPosition& pos);
	CardTwelve();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	Player* LeastWallet(Grid* pGrid, Player* pPlayer);
	Card* MaxStation(Grid* pGrid, Player* pPlayer);
	~CardTwelve();
	virtual Card* GetCopy();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);

};*/

