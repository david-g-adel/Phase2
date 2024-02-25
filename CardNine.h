#pragma once
#include "Card.h"

class CardNine : public Card
{
protected:
	bool firstCardInitialized;
	static bool isOwned;
	static Player* Owner;
	static int cardPrice_9;
	static int fees_9;

public:
	CardNine(const CellPosition& pos);
	CardNine(const CellPosition& pos,int price,int fees);
	CardNine();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void SetOwner_9(Player* pPlayer);
	virtual Card* GetCopy();
	~CardNine();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};