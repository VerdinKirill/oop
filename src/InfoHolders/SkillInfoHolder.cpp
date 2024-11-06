#include "SkillInfoHolder.h"

SkillInfoHolder::SkillInfoHolder(std::optional<ShipManager*> ship_manager, std::optional<Field*> field , std::optional<Pos*> pos)
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
	if (pos == std::nullopt)
	{
		this->pos = Pos{0, 0};
	}
	else
	{
		this->pos = *pos.value();
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

Pos& SkillInfoHolder::getPos()
{
	return this->pos;
}


void SkillInfoHolder::setShipManager(ShipManager& ship_manager)
{
	this->ship_manager = &ship_manager;
}
void SkillInfoHolder::setField(Field& field)
{
	this->field = &field;
	
}
void SkillInfoHolder::setPos(Pos& pos)
{
	this->pos = pos;
}