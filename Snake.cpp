#include "Snake.h"
#include"Ladder.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	if (startCellPos.GetCellNum() > endCellPos.GetCellNum() && startCellPos.HCell() == endCellPos.HCell())
	{
		this->endCellPos = endCellPos;
		
	}

}
Snake::Snake() : GameObject()
{
	endCellPos = 0; //Default Constructor
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	(pGrid->GetOutput())->PrintMessage("you have reached a snake. click to continue... ");
	(pGrid->GetInput()->GetCellClicked());

	
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (pGrid->getObj(endCellPos) != NULL)
	{
		pGrid->getObj(endCellPos)->Apply(pGrid, pPlayer);
		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}


}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
void Snake::Save(ofstream& OutFile, Object obj)
{
	if (obj == ObjectSnake)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum()<<endl;
	}
}
void Snake::Load(ifstream& Infile)
{
	int startCell = 0;
	int endCell = 0;
	Infile >> startCell >> endCell;
	position = startCell;
	endCellPos = endCell;
}
bool Snake::IsOverlapping(GameObject* newObj)
{
	Ladder* passedLadder = dynamic_cast<Ladder*>(newObj);
	Snake* passedSnake = dynamic_cast<Snake*>(newObj);
	if (passedLadder != NULL)
	{
		if (passedLadder->GetPosition().GetCellNum() == endCellPos.GetCellNum())
			return true;
	}
	else if (passedSnake != NULL)
	{
		for (int i = position.GetCellNum();i < endCellPos.GetCellNum();i += 11)
		{
			if (passedSnake->position.GetCellNum() == i)
			{
				return true;
			}
		}
	}
	else return false;
}