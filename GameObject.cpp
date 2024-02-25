#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position

}
GameObject::GameObject()
{
	position = 0; // Default Constructor

}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}