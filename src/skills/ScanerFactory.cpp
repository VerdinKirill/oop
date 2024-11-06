#include "ScanerFactory.h"


Skill *ScanerFactory::createSkill(SkillInfoHolder* skill_holder)
{	
	auto& field = skill_holder->getField();
	auto& pos = skill_holder->getPos();
	return new Scaner(field, pos);
}