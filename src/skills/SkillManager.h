#pragma once

#include <queue>
#include "Skill.h"
#include "SkillFactory.h"
#include "BombardmentFactory.h"
#include "DoubleDamageFactory.h"
#include "ScanerFactory.h"
#include "../InfoHolders/SkillResultInfoHolder.h"
#include <optional>
#include <iostream>
#include <string>


class SkillManager
{
	std::queue<SkillFactory*> skill_factory_queue;
	std::vector<SkillFactory*> pull_of_skills;
	public:
	SkillManager(std::optional<std::vector<SkillFactory*>> skill_factories= std::nullopt);
	void update(SkillResultInfoHolder& skill_result);
	SkillFactory* getSkill();
	void addSkill();
	void printAvailableSkills();
	int size();
};

