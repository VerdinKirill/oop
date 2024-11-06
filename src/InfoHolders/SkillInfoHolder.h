#pragma once
#include "InfoHolder.h"
#include "../Field.h"
#include "../ShipManager.h"
#include <optional>

class Field;
class Shipmanager;


class SkillInfoHolder: public InfoHolder{
	ShipManager* ship_manager;
	Field* field;
	Pos pos;
	public:
		SkillInfoHolder(std::optional<ShipManager*> ship_manager = std::nullopt, std::optional<Field*> field = std::nullopt, std::optional<Pos*> pos = std::nullopt);
		void read() override{};
		ShipManager& getShipManager();
		Field& getField();
		Pos& getPos();
		void setShipManager(ShipManager& ship_manager);
		void setField(Field& field);
		void setPos(Pos& pos);
};
