#pragma once
#include "Skill.h"
#include "../Field.h"
#include "../ShipManager.h"
#include "../InfoHolders/SkillInfoHolder.h"
#include <optional>

class SkillFactory
{	
	public:
	virtual Skill *createSkill(SkillInfoHolder* skill_holder) = 0;
	virtual std::string getName() = 0;
	// virtual ~SkillFactory();
};