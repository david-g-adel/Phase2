#pragma once
#include "Card.h"
class CardFive :public Card
{
public:
	CardFive(const CellPosition& pos);
	CardFive();
	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardFive();
	virtual Card* GetCopy();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);

};