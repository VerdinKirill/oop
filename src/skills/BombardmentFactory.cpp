#include "BombardmentFactory.h"

Skill *BombardmentFactory::createSkill(SkillInfoHolder* skill_holder)
{
	return new Bombardment(skill_holder->getShipManager());
}

std::string BombardmentFactory::getName()
{
	return "Bombardment";
}


