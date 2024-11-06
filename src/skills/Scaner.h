#pragma once
#include "Skill.h"
#include "../Field.h"


class Scaner: public Skill{
	Field* field;
	Pos pos;
	public:
	Scaner(Field& field, Pos& pos);
	SkillResultInfoHolder& use() override;
};