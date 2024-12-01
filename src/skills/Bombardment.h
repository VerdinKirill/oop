#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Skill.h"
#include "../ShipManager.h"




class Bombardment : public Skill{
	ShipManager* ship_manager;
	public:
	Bombardment(ShipManager& ship_manager);
	SkillResultInfoHolder& use() override;
};

#endif