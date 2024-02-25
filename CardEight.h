#pragma once
#include "Card.h"
class CardEight :
    public Card
{
	int amount;
public:
	CardEight(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	CardEight();
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardEight();
	virtual Card* GetCopy();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};

