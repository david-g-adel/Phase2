#pragma once
#include "Card.h"
class CardFour : public Card
{

public:
	CardFour(const CellPosition& pos);
	CardFour();
	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardFour();
	virtual Card* GetCopy();
	virtual void CardFour::Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);

};