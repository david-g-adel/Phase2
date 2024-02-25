#pragma once
#include "Card.h"
class CardTwo :public Card
{
public:
	CardTwo(const CellPosition& pos);
	CardTwo();
	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardTwo();
	virtual Card* GetCopy();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};

