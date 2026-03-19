/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:30:44 by aboumall          #+#    #+#             */
/*   Updated: 2026/03/11 03:31:44 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


static bool printPseudoLiterals(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	} else if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	} else if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (printPseudoLiterals(literal))
		return;
	if (isInt(literal)) {
		convertInt(literal);
	} else if (isFloat(literal)) {
		convertFloat(literal);
	} else if (isDouble(literal)) {
		convertDouble(literal);
	} else if (isChar(literal)) {
		convertChar(literal);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && isDisplayableChar(literal[0]);
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
	char value = literal[0];
	
	int i_value = static_cast<int>(value);
	float f_value = static_cast<float>(value);
	double d_value = static_cast<double>(value);

	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << i_value << std::endl;
	std::cout << "float: " << f_value << "f" << std::endl;
	std::cout << "double: " << d_value << std::endl;	
}

#include <climits>

static int myStoi(const std::string& literal)
{
	long value = 0;
	size_t i = 0;
	bool isNegative = false;

	if (literal[i] == '-') {
		isNegative = true;
		i++;
	}
	for (; i < literal.length(); ++i) 
	{
		int digit = literal[i] - '0';
		value = value * 10 + digit;
		 if (value > (INT_MAX - digit) / 10)
            throw std::out_of_range("Integer overflow");
	}
	return isNegative ? -value : value;
}

#include <limits>

static float myStof(const std::string& literal)
{
	long double value = 0;
	size_t i = 0;
	bool isNegative = false;

	if (literal[i] == '-') {
		isNegative = true;
		i++;
	}
	for (; i < literal.length(); ++i) 
	{
		if (literal[i] == '.') {
			i++;
			long double fraction = 0;
			long double divisor = 1;
			for (; i < literal.length() && literal[i] != 'f'; ++i) {
				int digit = literal[i] - '0';
				fraction = fraction * 10 + digit;
				divisor *= 10;
			}
			value += fraction / divisor;
			break;
		}
		int digit = literal[i] - '0';
		value = value * 10 + digit;
		if (value > std::numeric_limits<float>::max())
			throw std::out_of_range("Float overflow");
	}
	return isNegative ? -value : value;
}

static double myStod(const std::string& literal)
{
	long double value = 0;
	size_t i = 0;
	bool isNegative = false;

	if (literal[i] == '-') {
		isNegative = true;
		i++;
	}
	for (; i < literal.length(); ++i) 
	{
		if (literal[i] == '.') {
			i++;
			long double fraction = 0;
			long double divisor = 1;
			for (; i < literal.length() && literal[i] != 'f'; ++i) {
				int digit = literal[i] - '0';
				fraction = fraction * 10 + digit;
				divisor *= 10;
			}
			value += fraction / divisor;
			break;
		}
		int digit = literal[i] - '0';
		value = value * 10 + digit;
		if (value > std::numeric_limits<double>::max())
			throw std::out_of_range("Double overflow");
	}
	return isNegative ? -value : value;
}

void ScalarConverter::convertInt(const std::string& literal)
{
	int value = 0;
	bool error = false;
	
	try {
		value = myStoi(literal);
	} catch (const std::exception& e) {
		error = true;
	}
	
	char c_value = !error ? static_cast<char>(value) : 0;
	float f_value = static_cast<float>(value);
	double d_value = static_cast<double>(value);
	
	std::cout << "char: " << 
		(
			error ? "impossible" : (isDisplayableChar(c_value) 
			? std::string("'") + c_value + "'" : "Non displayable")
		) 
	<< std::endl;
	if (error)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << value << std::endl;
	std::cout << "float: " << f_value << "f" << std::endl;
	std::cout << "double: " << d_value << std::endl;
}
void ScalarConverter::convertFloat(const std::string& literal)
{
	float value = 0;
	bool error = false;

	try {
		value = myStof(literal);
	} catch (const std::exception& e) {
		error = true;
	}

	char c_value = !error ? static_cast<char>(value) : 0;
	int i_value = !error ? static_cast<int>(value) : 0;
	double d_value = static_cast<double>(value);

	std::cout << "char: " << 
		(
			error ? "impossible" : (isDisplayableChar(c_value) 
			? std::string("'") + c_value + "'" : "Non displayable")
		)
	<< std::endl;
	if (error)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i_value << std::endl;
	if (error)
		std::cout << "float: impossible" << std::endl;
	else
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << d_value << std::endl;
}
void ScalarConverter::convertDouble(const std::string& literal)
{
	double value = 0;
	bool error = false;

	try {
		value = myStod(literal);
	} catch (const std::exception& e) {
		error = true;
	}

	char c_value = !error ? static_cast<char>(value) : 0;
	int i_value = !error ? static_cast<int>(value) : 0;
	float f_value = !error ? static_cast<float>(value) : 0;

	std::cout << "char: " << 
		(
			error ? "impossible" : (isDisplayableChar(c_value) 
			? std::string("'") + c_value + "'" : "Non displayable")
		)
	<< std::endl;
	if (error)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i_value << std::endl;
	if (error)
		std::cout << "float: impossible" << std::endl;
	else
	std::cout << "float: " << f_value << "f" << std::endl;
	if (error)
		std::cout << "double: impossible" << std::endl;
	else
	if (error)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}



ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}