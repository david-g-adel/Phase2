#pragma once
#include "Card.h"
class CardSix :  public Card
{
	int cellnum;
public:
	CardSix(const CellPosition& pos); // A Constructor takes card position
	CardSix(CellPosition& pos, int);
	CardSix();
	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual ~CardSix(); // A Virtual Destructor
	virtual Card* GetCopy();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};

