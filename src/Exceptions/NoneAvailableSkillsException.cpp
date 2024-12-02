#include "NoneAvailableSkillsException.h"

NoneAvailableSkillsException::NoneAvailableSkillsException()
{
	message = "You tried to get skill, but you have not available skills!\n";
}

const char* NoneAvailableSkillsException::what() const noexcept
{
	return message.c_str();
}