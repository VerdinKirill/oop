#pragma once
#include <exception>
#include <string>

class ReaderException: public std::exception {
	private:
	std::string message;

	public:
	ReaderException(std::string message): message(message){};
	const char* what() const noexcept override;
};