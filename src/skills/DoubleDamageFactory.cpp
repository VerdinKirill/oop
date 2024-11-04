#include "DoubleDamageFactory.h"

Skill *createSkill(std::optional<Pos> pos = std::nullopt, std::optional<Field *> field = std::nullopt, std::optional<ShipManager *> = std::nullopt)
{	
	if (field == std::nullopt)
	{
		return nullptr;
	}
	return new DoubleDamage(*field.value());
}