#pragma once
#include "Card.h"
class CardEleven :public Card
{
protected:
	bool firstCardInitialized;
	static bool isOwned;
	static Player* Owner;
	static int cardPrice_11;
	static int fees_11;

public:
	CardEleven(const CellPosition& pos);
	CardEleven(const CellPosition& pos, int price, int fees);
	CardEleven();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void SetOwner_11(Player* pPlayer);
	virtual Card* GetCopy();
	~CardEleven();
	virtual void Save(ofstream& OutFile, Object obj);
	virtual void Load(ifstream& Infile);
	virtual bool IsOverlapping(GameObject* newObj);
};