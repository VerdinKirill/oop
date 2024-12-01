#ifndef SKILLFACTORY_H
#define SKILLFACTORY_H

#include "Skill.h"
#include "../Field.h"
#include "../ShipManager.h"
#include "../InfoHolders/SkillInfoHolder.h"
#include "SkillVisitor.h"
#include <optional>

class SkillVisitor;
class Skill;
class SkillInfoHolder;

class SkillFactory
{	
	public:
	virtual Skill *createSkill(SkillInfoHolder* skill_holder) = 0;
	virtual std::string accept(SkillVisitor* visitor) = 0;
	virtual ~SkillFactory() = default;
};

#endif