#include "BombardmentFactory.h"

Skill *BombardmentFactory::createSkill(std::optional<Pos> pos, std::optional<Field *> field, std::optional<ShipManager *> ship_manager)
{
	if (ship_manager == std::nullopt)
	{
		return nullptr;
	}
	return new Bombardment(*(ship_manager.value()));
}

