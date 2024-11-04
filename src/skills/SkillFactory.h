#pragma once
#include "Skill.h"
#include "../Field.h"
#include "../ShipManager.h"
#include <optional>

class SkillFactory
{	
	public:
	virtual Skill *createSkill(std::optional<Pos> pos = std::nullopt,  std::optional<Field*> field = std::nullopt, std::optional<ShipManager*>  ship_manager = std::nullopt) = 0;
};