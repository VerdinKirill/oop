#pragma once
#include "SkillFactory.h"
#include "Bombardment.h"

class BombardmentFactory : public SkillFactory
{
public:
	Skill *createSkill(SkillInfoHolder* skill_holder) override;
};