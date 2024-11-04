#include "ScanerFactory.h"

Skill *ScanerFactory::createSkill(std::optional<Pos> pos, std::optional<Field *> field, std::optional<ShipManager *> ship_manager)
{
	if (pos == std::nullopt)
	{
		return nullptr;
	}
	if (field == std::nullopt)
	{
		return nullptr;
	}
	return new Scaner(*(field).value(), pos.value());
}