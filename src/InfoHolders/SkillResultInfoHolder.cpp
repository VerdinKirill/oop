#include "SkillResultInfoHolder.h"

SkillResultInfoHolder::SkillResultInfoHolder()
{
	this->is_battleship_cell = false;
	this->coords = nullptr;
	this->is_battleship_destroyed = false;
	this->current_damage = 1;
}

void SkillResultInfoHolder::set_is_battleship_cell(bool is_battleship_cell)
{
	this->is_battleship_cell = is_battleship_cell;
}

void SkillResultInfoHolder::set_is_battleship_destroyed(bool is_destroyed)
{
	this->is_battleship_destroyed = is_destroyed;
}

void SkillResultInfoHolder::set_pos(Pos& pos)
{
	this->coords = &pos;
}

void SkillResultInfoHolder::set_damage(int damage)
{
	this->current_damage = damage;
}

bool SkillResultInfoHolder::get_is_battleship_cell()
{
	return this->is_battleship_cell;
}

bool SkillResultInfoHolder::get_is_battleship_destroyed()
{
	return this->is_battleship_destroyed;
}

Pos& SkillResultInfoHolder::get_pos()
{
	return *(this->coords);
}

int SkillResultInfoHolder::get_damage()
{
	return this->current_damage;
}


