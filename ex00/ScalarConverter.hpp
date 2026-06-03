/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:27:47 by aboumall          #+#    #+#             */
/*   Updated: 2026/06/03 16:03:01 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdio>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convertInt(std::string literal, int& l_int, float& l_float, double& l_double, char& c);
		static void convertFloat(std::string literal, int& l_int, float& l_float, double& l_double, char& c);
		static void convertDouble(std::string literal, int& l_int, float& l_float, double& l_double, char& c);
		static void convertChar(std::string literal, int& l_int, float& l_float, double& l_double, char& c);

		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static bool isChar(const std::string& literal);
		
	public:
		static void convert(const std::string& literal);

};

#endif
