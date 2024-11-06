#pragma once
#include "SkillFactory.h"
#include "Scaner.h"


class ScanerFactory : public SkillFactory
{	
	public:
	Skill *createSkill(SkillInfoHolder* skill_holder) override;
};