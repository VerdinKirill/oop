#include "SkillResultInfoHolder.h"

SkillResultInfoHolder::SkillResultInfoHolder()
{
	this->is_battleship_cell = false;
	this->coords = {-1, -1};
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

void SkillResultInfoHolder::set_pos(std::pair<int, int>pos)
{
	this->coords = pos;
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

std::pair<int, int> SkillResultInfoHolder::get_pos()
{	
	if (this->coords.first != -1 || this->coords.second!=-1)
		return this->coords;
	return {-1, -1};
}

int SkillResultInfoHolder::get_damage()
{
	return this->current_damage;
}
void SkillResultInfoHolder::print()
{	

	std::cout << "damage:" << this->get_damage() << "\nisBattleship: " << this->get_is_battleship_cell()
    <<"\nPos: ";
	std::pair<int, int> pos;
	if ((pos = this->get_pos()).first == -1)
	{
		std::cout << "None\n";
	}
	else
	{
		std::cout << pos.first << " " << pos.second << '\n';
	}
}

