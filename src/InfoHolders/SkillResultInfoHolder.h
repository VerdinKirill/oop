#ifndef SKILLRESULTINFOHOLDER_H
#define SKILLRESULTINFOHOLDER_H

#include "InfoHolder.h"
#include "../Field.h"
#include <iostream>


struct Pos;

class SkillResultInfoHolder: public InfoHolder {
	bool is_battleship_cell;
	std::pair<int, int> coords;
	BattleshipCellState battleship_state;
	bool is_battleship_destroyed;
	int current_damage;
	public:
		SkillResultInfoHolder();
		void read() override{};
		void set_is_battleship_cell(bool is_battleship_cell);
		void set_pos(std::pair<int, int> coords);
		void set_is_battleship_destroyed(bool is_destroyed);
		void set_damage(int damage);
		bool get_is_battleship_cell();
		bool get_is_battleship_destroyed();
		std::pair<int, int> get_pos();
		int get_damage();
		void print();
};

#endif