#pragma once
#include "Card.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition& pos);
	CardSeven();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardSeven();
	virtual Card* GetCopy();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};