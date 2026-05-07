/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:30:44 by aboumall          #+#    #+#             */
/*   Updated: 2026/05/07 19:19:32 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

static void convertInt(std::string literal);

void ScalarConverter::convert(const std::string& literal)
{
	std::stringstream ss(literal);
	int l_int;
	float l_float;
	double l_double;
	char c;
	
	
	if ((ss >> l_int) && !(ss >> c)) {
		convertInt(literal);
	} else if ((ss >> l_float) && !(ss >> c)) {
		throw std::runtime_error("Not implemented float convert");
		// convertFloat(literal);
	} else if ((ss >> l_double) && !(ss >> c)) {
		throw std::runtime_error("Not implemented double convert");
		// convertDouble(literal);
	} else if (ss >> c) {
		throw std::runtime_error("Not implemented char convert");
		// convertChar(literal);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
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

static void convertInt(std::string literal)
{
	std::stringstream ss(literal);
	int l_int;
	float l_float;
	double l_double;
	char c;

	ss >> l_int;
	l_float = static_cast<float>(l_int);
	l_double = static_cast<double>(l_int);
	c = static_cast<char>(l_int);

	std::cout << fixed2;
	if (isDisplayableChar(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << l_int << std::endl;
	std::cout << "float: " << l_float << "f" << std::endl;
	std::cout << "double: " << l_double << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}
