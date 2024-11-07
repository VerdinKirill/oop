#pragma once
#include <exception>
#include <string>

class ShipNearAnotherException: public std::exception {
	
	std::string message;

	public:
	ShipNearAnotherException();
	const char* what() const noexcept override;
};