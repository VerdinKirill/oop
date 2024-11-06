#pragma once
#include "Skill.h"
#include "../Field.h"

class DoubleDamage : public Skill{
	Field* field;
	public:
	DoubleDamage(Field& field);
	SkillResultInfoHolder& use() override;

};