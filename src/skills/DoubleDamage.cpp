#include "DoubleDamage.h"

DoubleDamage::DoubleDamage(Field& field)
{
	this->field = &field;
}

SkillResultInfoHolder& DoubleDamage::use()
{
	auto result_info = new SkillResultInfoHolder();
	result_info->set_damage(2);
	return *result_info;
}