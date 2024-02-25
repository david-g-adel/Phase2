#pragma once
#include "Card.h"
class CardTen :public Card
{
protected:
	bool firstCardInitialized;
	static bool isOwned;
	static Player* Owner;
	static int cardPrice_10;
	static int fees_10;
public:
	CardTen(const CellPosition& pos);
	CardTen(const CellPosition& pos, int price, int fees);
	CardTen();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void SetOwner_10(Player* pPlayer);
	virtual Card* GetCopy();
	~CardTen();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};