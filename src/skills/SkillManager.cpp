#include "SkillManager.h"


SkillManager::SkillManager(std::optional<std::vector<SkillFactory*>> skill_factories)
{	
	int random_index;
	this->skill_factory_queue = std::queue<SkillFactory*>{};
	this->pull_of_skills = skill_factories.value_or(std::vector<SkillFactory*>{new ScanerFactory, new BombardmentFactory, new DoubleDamageFactory});
	std::vector<SkillFactory*> skill_factory_array(pull_of_skills);
	while (skill_factory_array.size() != 0)
	{
		random_index = (std::rand() % skill_factory_array.size());
		this->skill_factory_queue.push(skill_factory_array[random_index]);
		skill_factory_array.erase(skill_factory_array.begin() + random_index);
	}
}

void SkillManager::addSkill()
{
	int random_index;
	random_index = (std::rand() % pull_of_skills.size());
	this->skill_factory_queue.push(pull_of_skills[random_index]);
}

void SkillManager::update(SkillResultInfoHolder& skill_result)
{
	if (skill_result.get_is_battleship_destroyed())
	{
		this->addSkill();
	}
}

void SkillManager::printAvailableSkills()
{
	auto queue(this->skill_factory_queue);
	std::cout << "available skills:\n";
	for(; !queue.empty(); queue.pop())
	{
		std::cout << queue.front()->getName() << '\n';
	}
}

SkillFactory* SkillManager::getSkill()
{
	auto output = this->skill_factory_queue.front();
	this->skill_factory_queue.pop();
	return output;
}

int SkillManager::size()
{
	return this->skill_factory_queue.size();
}



