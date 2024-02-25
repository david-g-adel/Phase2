#include "Player.h"

#include "GameObject.h"
#include "Player.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	if (pCell->GetCellPosition().IsValidCell() == true)
	{
		this->pCell = pCell;
	}
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet >= 0)
	{
		this->wallet = wallet;
	}
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::setjustRolledDiceNum(int dicenum)
{
	justRolledDiceNum = dicenum;
}
int Player::getjustRolledDiceNum()
{
	return justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	turnCount++;///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	if (stopped > 0)
	{
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("You cant play this round ");
		pGrid->UpdatePlayerCell(this, pCell->GetCellPosition());
		stopped--;
		if (turnCount == 3)
		{
			turnCount = 0;
		}

	}
	else
	{


		if (turnCount == 3)
		{
			turnCount = 0;
			wallet += 10 * diceNumber;
			return;
		}
		justRolledDiceNum = diceNumber;
		// == Here are some guideline steps (numbered below) to implement this function ==
		if (wallet < 1)
		{
			return;
		}
		else
		{
			Output* pOut = pGrid->GetOutput();
			CellPosition pos = pCell->GetCellPosition();
			pos = pos.AddCellNum(justRolledDiceNum);
			
			
			pGrid->UpdatePlayerCell(this, pos);
			pCell->GetGameObject()->Apply(pGrid, this);
			if (pos.GetCellNum() + justRolledDiceNum == 100)
			{
				pOut->PrintMessage("PLAYER" + to_string(playerNum) + (" YOU WON!!!"));
				pGrid->SetEndGame(true);
			}
		}

	}
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::SetTurnCount(int t)
{
	turnCount = t;
}


void Player::setstopped(int s)
{
	if (s > 0)
	{
		stopped = s;
	}
	else
		stopped = 0;
}
int Player::getstopped()
{
	return stopped;
}
void Player::MoveToCell(Grid* pGrid, CellPosition C)
{
	CellPosition pos = C;
	pGrid->UpdatePlayerCell(this, pos);
	if (pCell->GetGameObject() != NULL)
	{
		pCell->GetGameObject()->Apply(pGrid, this);
	}

}
void Player::SetStepCount(Cell* pCell)
{
	stepCount = pCell->GetCellPosition().GetCellNum();
}
int Player::GetStepCount()
{
	return stepCount;
}
void Player::Restart(Grid*pGrid)
{
	wallet = 100;
	turnCount = 0;
	pGrid->UpdatePlayerCell(this, 1);
}