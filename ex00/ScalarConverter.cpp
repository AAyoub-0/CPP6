/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:30:44 by aboumall          #+#    #+#             */
/*   Updated: 2026/02/04 04:10:01 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void ScalarConverter::convert(const std::string& literal)
{
	// Implementation of conversion logic goes here
	std::cout << "Converting literal: " << literal << std::endl;
	// This is a placeholder implementation
	if (isChar(literal)) {
		std::cout << "It's a char!" << std::endl;
	} else if (isInt(literal)) {
		std::cout << "It's an int!" << std::endl;
	} else if (isFloat(literal)) {
		std::cout << "It's a float!" << std::endl;
	} else if (isDouble(literal)) {
		std::cout << "It's a double!" << std::endl;
	} else {
		std::cout << "Unknown type!" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& literal)
{
	// Implementation to check if the literal is a char
	return literal.length() == 1 && !isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	try {
		size_t sign;

		sign = literal.find("-");
		if (sign != std::string::npos && sign != 0)
			return false;
		if (literal.find_first_not_of("0123456789",
				(sign != std::string::npos) ? 1 : 0) != std::string::npos)
			return false;
		return true;
	} catch (...) {
		return false;
	}
}

bool isValidFloatFormat(const std::string& literal)
{
	size_t dotCount = 0;
	size_t fCount = 0;

	for (size_t i = 0; i < literal.length(); ++i) {
		if (literal[i] == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
			if (i == 0 || i == literal.length() - 1)
				return false;
			else if (literal[i + 1] == 'f')
				return false;
		} else if (literal[i] == 'f') {
			fCount++;
			if (i != literal.length() - 1)
				return false;
		}
	}
	if (fCount != 1)
		return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	try {
		size_t sign;

		sign = literal.find("-");
		if (sign != std::string::npos && sign != 0)
			return false;
		if (!isValidFloatFormat(literal))
			return false;
		if (literal.find_first_not_of(".0123456789f",
				(sign != std::string::npos) ? 1 : 0) != std::string::npos)
			return false;
		return true;
	} catch (...) {
		return false;
	}
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	try {
		size_t sign;

		sign = literal.find("-");
		if (sign != std::string::npos && sign != 0)
			return false;
		if (literal.find_first_not_of(".0123456789",
				(sign != std::string::npos) ? 1 : 0) != std::string::npos)
			return false;
		return true;
	} catch (...) {
		return false;
	}
}

bool ScalarConverter::isDisplayableChar(int value)
{
	return value >= 32 && value <= 126;
}

void ScalarConverter::convertChar(const std::string& literal)
{
	(void) literal;
	throw std::logic_error("Not implemented yet");
}

void ScalarConverter::convertInt(const std::string& literal)
{
	(void) literal;
	throw std::logic_error("Not implemented yet");
}
void ScalarConverter::convertFloat(const std::string& literal)
{
	(void) literal;
	throw std::logic_error("Not implemented yet");
}
void ScalarConverter::convertDouble(const std::string& literal)
{
	(void) literal;
	throw std::logic_error("Not implemented yet");
}



ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}