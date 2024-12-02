#include "ScanerFactory.h"


Skill *ScanerFactory::createSkill(SkillInfoHolder* skill_holder)
{	
	auto& field = skill_holder->getField();
	skill_holder->read();
	skill_holder->getCoords().read();
	auto pos = skill_holder->getCoords().getCoords();
	return new Scaner(field, pos);
}

std::string ScanerFactory::accept(SkillVisitor* visitor)
{
	return visitor->visit(this);
}
