#include "Deserialization.h"


void Deserialization::from_json(ShipManager& shipManager, std::string key) {
    const auto& jsm = j.at(key);
    // std::vector<int> shipSizes;
	int count4len = 0;
	int count3len = 0;
	int count2len = 0;
	int count1len = 0;


    for (const auto& jship : jsm) {
        auto len = jship.at("length");
		if (len == 4)
			count4len++;
		if (len == 3)
			count3len++;
		if (len==2)
			count2len++;
		if (len==1)
			count1len++;
    }
	// std::cout <<count4len << " " <<count3len << " " <<count2len << " " << count1len << '\n';
    shipManager = ShipManager(count4len, count3len, count2len, count1len);

    for (size_t i = 0; i < shipManager.GetNumberBattleships(); i++) {
        std::string key = "ship" + std::to_string(i);
        Battleship& ship = shipManager[i];
		ship.SetDirection(Direction(jsm.at(key).at("direction")));
		auto segments = jsm.at(key).at("segments");
		auto it = segments.begin();
        for (int j = 0; j < ship.GetLength() && it < segments.end(); j++, ++it) {
            BattleshipCell& segment = ship[j];
			auto segmentJson = it.value();
			segment.SetState(BattleshipCellState(segmentJson.at("State")));
            std::pair<int, int> coordinates;
            coordinates.first = segmentJson.at("y");
            coordinates.second = segmentJson.at("x");
            segment.setCoordinates(coordinates);
            std::cout << segment.getCoordinates().first << " " << segment.getCoordinates().second << "coordinates of battleship cell\n";
        }
    }
	std::cout << "ended parse json for shipmanager\n";
}

void Deserialization::from_json(Field& field, std::string key) {
    const auto& jf = j.at(key);
    field = Field(jf.at("width"), jf.at("height"));

    for (int y = 0; y < field.GetHeight(); y++) {
        for (int x = 0; x < field.GetWidth(); x++) {
            std::string key = "cell" + std::to_string(y) + std::to_string(x);
            FieldCell& cell = field[y][x];
			cell.setIdBattleship(jf.at(key).at("idBattleShip"));
            cell.SetFieldCellState(FieldCellState(jf.at(key).at("state")));
			cell.setIsHead(jf.at(key).at("isHead"));
        }
    }
	std::cout << "endedfor field\n";
}

void Deserialization::from_json(SkillManager& skillManager, std::string key) {
    const auto& jam = j.at(key);
    skillManager = SkillManager();
	skillManager.pop();
	skillManager.pop();
	skillManager.pop();
	std::cout << "ya tut";
    for (const auto& jability : jam.at("abilities")) {
       if (jability == "DoubleDamage") {
           skillManager.addSkill(new DoubleDamageFactory());
       }
       else if(jability == "Scaner"){
           skillManager.addSkill(new ScanerFactory());
       }
       else if (jability == "Bombardment") {
           skillManager.addSkill(new BombardmentFactory());
       }
    }
	std::cout << "Ended parse json for skillManager";
}