#pragma once

#include <exception>
#include <string>

class UnableOpenFileException : public std::exception
{
    std::string message;

public:
    UnableOpenFileException();
    const char *what() const noexcept override;
};