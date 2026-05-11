/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:30:44 by aboumall          #+#    #+#             */
/*   Updated: 2026/05/11 20:06:00 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

std::ostream& fixed2(std::ostream& os);
static bool isDisplayableChar(int value);
static bool isPseudoLiteral(const std::string& literal);
static void printPseudoLiterals(const std::string& literal);

void ScalarConverter::convert(const std::string& literal)
{
	std::istringstream iss(literal);
	std::cout << "Literal: " << literal << std::endl;
	int l_int = 0;
	float l_float = 0.0f;
	double l_double = 0.0;
	char c = 0;
	
	if (isPseudoLiteral(literal))
	{
		printPseudoLiterals(literal);
		return ;
	}
	else
	if (isInt(literal)) {
		std::cout << "Detected type: int" << std::endl;
		convertInt(literal, l_int, l_float, l_double, c);
	} else if (isFloat(literal)) {
		std::cout << "Detected type: float" << std::endl;
		convertFloat(literal, l_int, l_float, l_double, c);
	} else if (isDouble(literal)) {
		std::cout << "Detected type: double" << std::endl;
		convertDouble(literal, l_int, l_float, l_double, c);
	} else if (isChar(literal)) {
		std::cout << "Detected type: char" << std::endl;
		convertChar(literal, l_int, l_float, l_double, c);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	std::cout << fixed2;
	if (isDisplayableChar(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (l_int == 0 && (l_float > 0.0f || l_double > 0.0))
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << l_int << std::endl;
	if (l_float == 0.0f && l_double > 0.0)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << l_float << "f" << std::endl;
	std::cout << "double: " << l_double << std::endl;
}

std::ostream& fixed2(std::ostream& os)
{
	std::cout << std::fixed << std::setprecision(1);
	return os;
}

static bool isDisplayableChar(int value)
{
	return value >= 32 && value <= 126;
}

void ScalarConverter::convertInt(std::string literal, int& l_int, float& l_float, double& l_double, char& c)
{
	std::stringstream ss(literal);

	ss >> l_int;
	l_float = static_cast<float>(l_int);
	l_double = static_cast<double>(l_int);
	c = static_cast<char>(l_int);
}

void ScalarConverter::convertFloat(std::string literal, int& l_int, float& l_float, double& l_double, char& c)
{
	std::stringstream ss(literal);

	ss >> l_float;
	if (l_float > std::numeric_limits<int>::max() || l_float < std::numeric_limits<int>::min())
		l_int = 0;
	else
		l_int = static_cast<int>(l_float);
	l_double = static_cast<double>(l_float);
	c = static_cast<char>(l_float);
}

void ScalarConverter::convertDouble(std::string literal, int& l_int, float& l_float, double& l_double, char& c)
{
	std::stringstream ss(literal);

	ss >> l_double;
	if (l_double > std::numeric_limits<int>::max() || l_double < std::numeric_limits<int>::min())
		l_int = 0;
	else
		l_int = static_cast<int>(l_double);
	if (l_double > std::numeric_limits<float>::max() || l_double < -std::numeric_limits<float>::max())
		l_float = 0.0f;
	else
		l_float = static_cast<float>(l_double);
	c = static_cast<char>(l_double);
}

void ScalarConverter::convertChar(std::string literal, int& l_int, float& l_float, double& l_double, char& c)
{
	c = literal[0];
	l_int = static_cast<int>(c);
	l_float = static_cast<float>(c);
	l_double = static_cast<double>(c);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	std::istringstream iss(literal);
	int value;
	
	return (iss >> value) && (iss.peek() == EOF);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	std::istringstream iss(literal);
	float value;
	char f;

	return (iss >> value)
		&& (iss >> f) 
		&& (f == 'f')
		&& (iss.peek() == EOF);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	std::istringstream iss(literal);
	double value;
	
	return (iss >> value) && (iss.peek() == EOF);
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isprint(literal[0]);
}

static bool isPseudoLiteral(const std::string& literal)
{
	return literal == "nan" || literal == "nanf" ||
		   literal == "+inf" || literal == "+inff" ||
		   literal == "-inf" || literal == "-inff";
}

static void printPseudoLiterals(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}
