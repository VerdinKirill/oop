#pragma once

#include <exception>
#include <string>

class ModifiedJsonException : public std::exception {
	std::string message;
	public:
	ModifiedJsonException(std::string message);
	const char* what() const noexcept override;
};