#pragma once
#include "SkillFactory.h"
#include "Scaner.h"

class ScanerFactory : public SkillFactory
{	
	public:
	Skill *createSkill(std::optional<Pos> pos = std::nullopt, std::optional<Field*> field = std::nullopt, std::optional<ShipManager*> = std::nullopt) override;
};