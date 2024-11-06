#pragma once

#include "InfoHolder.h"
#include "../Field.h"

struct Pos;

class SkillResultInfoHolder: public InfoHolder {
	bool is_battleship_cell;
	Pos* coords;
	BattleshipCellState battleship_state;
	bool is_battleship_destroyed;
	int current_damage;
	public:
		SkillResultInfoHolder();
		void read() override{};
		void set_is_battleship_cell(bool is_battleship_cell);
		void set_pos(Pos& coords);
		void set_is_battleship_destroyed(bool is_destroyed);
		void set_damage(int damage);
		bool get_is_battleship_cell();
		bool get_is_battleship_destroyed();
		Pos& get_pos();
		int get_damage();
};