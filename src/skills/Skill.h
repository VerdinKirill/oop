#pragma once
#include "../InfoHolders/SkillResultInfoHolder.h"

class Skill {
	public:
	virtual SkillResultInfoHolder& use() = 0;
	// virtual ~Skill();
};