#ifndef DOUBLEDAMAGEFACTORY_H
#define DOUBLEDAMAGEFACTORY_H
#include "SkillFactory.h"
#include "DoubleDamage.h"

class SkillVisitor;

class DoubleDamageFactory : public SkillFactory
{	
	public:
	Skill *createSkill(SkillInfoHolder* skill_holder) override;
	std::string accept(SkillVisitor* visitor) override;

};

#endif