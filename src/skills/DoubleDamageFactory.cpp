#include "DoubleDamageFactory.h"

Skill* DoubleDamageFactory::createSkill(SkillInfoHolder* skill_holder)
{	
	return new DoubleDamage(skill_holder->getField());
}

std::string DoubleDamageFactory::getName()
{
	return "DoubleDamage";
}
