#pragma once
#include "Card.h"
class CardThree : public Card
{

	public:
		CardThree(const CellPosition& pos);
		CardThree();
		virtual void ReadCardParameters(Grid* pGrid);

		virtual void Apply(Grid* pGrid, Player* pPlayer);
		~CardThree();
		virtual Card* GetCopy();
		virtual void Save(ofstream& OutFile, Object obj);
		virtual void Load(ifstream& Infile);
		virtual bool IsOverlapping(GameObject* newObj);

};

