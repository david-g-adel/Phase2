#include "Ladder.h"
#include "Player.h"
#include "Card.h"
#include "GameObject.h"
#include "CellPosition.h"
#include "Snake.h"
Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	if (startCellPos.GetCellNum() < endCellPos.GetCellNum() && startCellPos.HCell() == endCellPos.HCell())
	{
		this->endCellPos = endCellPos;
	}

}
Ladder::Ladder() :GameObject()
{
	endCellPos = 0; //Default Constructor
}

///TODO: Do the needed validation
void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintMessageAndWait("you have reached a ladder. click to continue... ");
	
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (pGrid->getObj(endCellPos)!=NULL)
	{
		pGrid->getObj(endCellPos)->Apply(pGrid, pPlayer);
		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
void Ladder::Save(ofstream& OutFile, Object obj)
{
	if (obj==ObjectLadder)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum()<<endl;
	}
}
void Ladder::Load(ifstream& Infile)
{
	int startCell = 0;
	int endCell = 0;
	Infile >> startCell >> endCell;
	position = startCell;
	endCellPos = endCell;
}
bool Ladder::IsOverlapping(GameObject* newObj)
{
	Ladder* passedLadder = dynamic_cast<Ladder*>(newObj);
	Snake*passedSnake= dynamic_cast<Snake*>(newObj);
	if (passedSnake != NULL)
	{
		if (passedSnake->GetPosition().GetCellNum() == endCellPos.GetCellNum())
			return true;
	}
	else if (passedLadder != NULL)
	{
		for (int i = position.GetCellNum();i < endCellPos.GetCellNum();i += 11)
		{
			if (passedLadder->position.GetCellNum() == i)
			{
				return true;
			}
		}
	}
	else return false;
}
