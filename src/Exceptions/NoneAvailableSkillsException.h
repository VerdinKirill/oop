// #pragma once

#ifndef NONEAVAILABLESKILLEXCEPTIONS_H
#define NONEAVAILABLESKILLEXCEPTIONS_H
#include <exception>
#include <string>

class NoneAvailableSkillsException: public std::exception {
	
	std::string message;

	public:
	NoneAvailableSkillsException();
	const char* what() const noexcept override;
};

#endif