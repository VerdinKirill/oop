// #pragma once
#ifndef BOTEXCEPTION_H
#define BOTEXCEPTION_H

#include <exception>
#include <string>


class BotException : public std::exception {
	std::string message;

	public:
	BotException(std::string message);
	const char* what() const noexcept override;
};

#endif