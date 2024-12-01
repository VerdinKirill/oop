#pragma once

#ifndef OUTOFBONDSEXCEPTION_H
#define OUTOFBONDSEXCEPTION_H

#include <exception>
#include <string>

class OutOfBondsException: public std::exception {
	
	std::string message;

	public:
	OutOfBondsException();
	const char* what() const noexcept override;
};

#endif