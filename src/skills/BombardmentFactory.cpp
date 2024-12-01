#include "BombardmentFactory.h"

Skill *BombardmentFactory::createSkill(SkillInfoHolder* skill_holder)
{
	return new Bombardment(skill_holder->getShipManager());
}

std::string BombardmentFactory::accept(SkillVisitor* visitor)
{
	return visitor->visit(this);
}


