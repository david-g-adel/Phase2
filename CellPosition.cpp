#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	vCell = 0;
	hCell = 0;
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{

	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}
	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;///TODO: Implement this function as described in the .h file (don't forget the validation)

	}
	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if (vCell != -1 && hCell != -1)
		return true;///TODO: Implement this function as described in the .h file


	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{

	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	int v = cellPosition.VCell();
	int h = cellPosition.HCell();
	int CellNo;
	if (v == 8)
	{
		CellNo = 1 + h;
	}
	else if (v == 7)
	{
		CellNo = 12 + h;
	}
	else if (v == 6)
	{
		CellNo = 23 + h;
	}
	else if (v == 5)
	{
		CellNo = 34 + h;
	}
	else if (v == 4)
	{
		CellNo = 45 + h;
	}
	else if (v == 3)
	{
		CellNo = 56 + h;
	}
	else if (v == 2)
	{
		CellNo = 67 + h;
	}
	else if (v == 1)
	{
		CellNo = 78 + h;
	}
	else if (v == 0)
	{
		CellNo = 89 + h;
	}
	return CellNo;

	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file


 // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	int v = -1;
	int h = -1;
	if (cellNum >= 1 && cellNum <= 11)
	{
		v = 8;
		h = cellNum - 1;

	}
	else if (cellNum >= 12 && cellNum <= 22)
	{
		v = 7;
		h = cellNum - 12;

	}
	else if (cellNum >= 23 && cellNum <= 33)
	{
		v = 6;
		h = cellNum - 23;

	}
	else if (cellNum >= 34 && cellNum <= 44)
	{
		v = 5;
		h = cellNum - 34;

	}
	else if (cellNum >= 45 && cellNum <= 55)
	{
		v = 4;
		h = cellNum - 45;

	}
	else if (cellNum >= 56 && cellNum <= 66)
	{
		v = 3;
		h = cellNum - 56;

	}
	else if (cellNum >= 67 && cellNum <= 77)
	{
		v = 2;
		h = cellNum - 67;

	}
	else if (cellNum >= 78 && cellNum <= 88)
	{
		v = 1;
		h = cellNum - 78;

	}
	else if (cellNum >= 89 && cellNum <= 99)
	{
		v = 0;
		h = cellNum - 89;

	}
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	position.SetVCell(v);
	position.SetHCell(h);

	/// TODO: Implement this function as described in the .h file


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}
CellPosition CellPosition::AddCellNum(int addedNum)
{
	int CellNumber = GetCellNum();
	CellNumber = CellNumber + addedNum;
	CellPosition P=GetCellPositionFromNum(CellNumber);
	return P;
	// Note: this function updates the data members (vCell and hCell) of the calling object

}