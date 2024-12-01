#ifndef BOMBARDMENTFACTORY_H
#define BOMBARDMENTFACTORY_H
#include "SkillFactory.h"
#include "Bombardment.h"

class SkillVisitor;

class BombardmentFactory : public SkillFactory
{
public:
	Skill *createSkill(SkillInfoHolder *skill_holder) override;
	std::string accept(SkillVisitor *visitor) override;
};

#endif