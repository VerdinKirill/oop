#pragma once

#include "../ShipManager.h"
#include "../Field.h"
#include "../skills/SkillManager.h"

#include <string.h>
#include "../libraries/json.hpp"

class Deserialization {
    private:
        nlohmann::json& j; 
    public:
        Deserialization(nlohmann::json& j) : j(j) {};

        void from_json(ShipManager& shipManager, std::string key);
        void from_json(Field& field, std::string key);
        void from_json(SkillManager& abilityManager, std::string key);
};