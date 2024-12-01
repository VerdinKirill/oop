#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Skill.h"
#include "../Field.h"


class DoubleDamage : public Skill{
	Field* field;
	public:
	DoubleDamage(Field& field);
	SkillResultInfoHolder& use() override;

};

#endif


