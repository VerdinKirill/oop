#include "SkillInfoHolder.h"
SkillInfoHolder::SkillInfoHolder(std::optional<ShipManager*> ship_manager, std::optional<Field*> field, std::optional<CoordHolder> coords):coords(coords.value())
{
	if (ship_manager == std::nullopt)
	{
		this->ship_manager = nullptr;
	}
	else
	{
		this->ship_manager = ship_manager.value();
	}
	if (field == std::nullopt)
	{
		this->field = nullptr;
	}
	else
	{
		this->field = field.value();
	}
}

ShipManager &SkillInfoHolder::getShipManager()
{
	return *(this->ship_manager);
}

Field &SkillInfoHolder::getField()
{
	return *(this->field);
}

CoordHolder& SkillInfoHolder::getCoords()
{
	return this->coords;
}


void SkillInfoHolder::setShipManager(ShipManager& ship_manager)
{
	this->ship_manager = &ship_manager;
}
void SkillInfoHolder::setField(Field& field)
{
	this->field = &field;
	
}
void SkillInfoHolder::setCoords(CoordHolder& pos)
{
	this->coords = pos;
}