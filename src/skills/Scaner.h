#ifndef SCANNER_H
#define SCANNER_H
#include "Skill.h"
#include "../Field.h"





class Scaner: public Skill{
	Field* field;
	std::pair<int, int> pos;
	public:
	Scaner(Field& field, std::pair<int, int> pos);
	SkillResultInfoHolder& use() override;
};

#endif