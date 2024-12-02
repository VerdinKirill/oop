#ifndef SCANERFACTORY_H
#define SCANERFACTORY_H
#include "Scaner.h"
#include "SkillFactory.h"

class SkillVisitor;


class ScanerFactory : public SkillFactory
{	
	public:
	Skill *createSkill(SkillInfoHolder* skill_holder) override;
	std::string accept(SkillVisitor* visitor) override;

};

#endif