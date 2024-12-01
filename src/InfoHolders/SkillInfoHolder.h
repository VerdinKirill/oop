#ifndef SKILLINFOHOLDER_H
#define SKILLINFOHOLDER_H

#include "InfoHolder.h"
#include "../Field.h"
#include "coordHolder.h"
#include "../ShipManager.h"
#include <optional>



class Field;
class Shipmanager;


class SkillInfoHolder: public InfoHolder{
	ShipManager* ship_manager;
	Field* field;
	CoordHolder& coords;
	public:
		SkillInfoHolder(std::optional<ShipManager*> ship_manager = std::nullopt, std::optional<Field*> field = std::nullopt, std::optional<CoordHolder> coords = std::nullopt);
		void read() override{};
		ShipManager& getShipManager();
		Field& getField();
		CoordHolder& getCoords();
		void setShipManager(ShipManager& ship_manager);
		void setField(Field& field);
		void setCoords(CoordHolder& coords);
};

#endif
