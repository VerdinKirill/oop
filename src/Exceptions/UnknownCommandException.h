// #pragma once
#ifndef UNKNOWNCOMMANDEXCEPTION_H
#define UNKNOWNCOMMANDEXCEPTION_H
#include <exception>
#include <string>



class UnknownCommandException: public std::exception {
	
	std::string message;

	public:
	UnknownCommandException(char command);
	const char* what() const noexcept override;
};

#endif