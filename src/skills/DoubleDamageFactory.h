#pragma once
#include "SkillFactory.h"
#include "DoubleDamage.h"

class DoubleDamageFactory : public SkillFactory
{	
	public:
	Skill *createSkill(SkillInfoHolder* skill_holder) override;
};