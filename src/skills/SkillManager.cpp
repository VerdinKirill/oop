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

void SkillManager::addSkill(std::optional<SkillFactory*> skill)
{
	int random_index;
	random_index = (std::rand() % pull_of_skills.size());
	this->skill_factory_queue.push(skill.value_or(pull_of_skills[random_index]));
}

void SkillManager::update(SkillResultInfoHolder& skill_result)
{
	if (skill_result.get_is_battleship_destroyed())
	{
		this->addSkill();
	}
}

SkillFactory* SkillManager :: operator[](int n)
{	
	auto element = this->skill_factory_queue.front();
	std::vector<SkillFactory*> skill_factory_array;
	int num = skill_factory_queue.size();
	for (int i = 0; i < num; i++)
	{
		skill_factory_array.push_back(this->skill_factory_queue.front());
		skill_factory_queue.pop();
	}
	for (int i = 0; i < skill_factory_array.size(); i++)
	{
		skill_factory_queue.push(skill_factory_array[i]);
	}
	return skill_factory_array[n];
}


Skill* SkillManager::getSkill(SkillInfoHolder& skill_holder)
{	
	if (this->skill_factory_queue.empty())
		throw NoneAvailableSkillsException();

	auto output = this->skill_factory_queue.front();
	// std::cout << "Current skill: "<<output->getName() << '\n';
	this->skill_factory_queue.pop();
	auto skill = output->createSkill(&skill_holder);
	return skill;
}

int SkillManager::size()
{
	return this->skill_factory_queue.size();
}

void SkillManager::pop()
{
	this->skill_factory_queue.pop();
}



