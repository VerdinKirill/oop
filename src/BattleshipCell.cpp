#include "BattleshipCell.h"
BattleshipCell::BattleshipCell()
{
	this -> hp = 2;
}

int BattleshipCell::GetHpValue()
{
	return hp;
}

void BattleshipCell::SetHpValue(int value)
{
	this->hp = value;
}

void BattleshipCell::AttackBattleshipCell()
{
	--this->hp;
}