#pragma once

#include "../ShipManager.h"
#include "../Field.h"
#include "../skills/SkillManager.h"
#include "../skills/SkillPrinter.h"

#include "../libraries/json.hpp"
#include <string.h>

class Serialization {
    private:
        nlohmann::json& j; 
    public:
        Serialization(nlohmann::json& j) : j(j) {};

        void to_json(ShipManager& shipManager, std::string key);
        void to_json(Field& field, std::string key);
        void to_json(SkillManager& abilityManager, std::string key);
};