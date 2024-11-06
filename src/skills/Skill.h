#pragma once
#include "../InfoHolders/SkillResultInfoHolder.h"
#include <string>

class Skill {
	public:
	virtual SkillResultInfoHolder& use() = 0;
	// virtual ~Skill();
};