/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 02:21:32 by aboumall          #+#    #+#             */
/*   Updated: 2026/06/03 16:28:55 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

int main(int argc, char** argv)
{
/* 	(void)argc;
	(void)argv;
	
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("999999999999999999999999999999999999999999.9");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483650.0f");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("42.2");
	std::cout << std::endl;
	ScalarConverter::convert("-42.2");
	std::cout << std::endl;
	ScalarConverter::convert("42.2f");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("invalid");
	std::cout << std::endl;
	ScalarConverter::convert("42.2ff");
	std::cout << std::endl;
	ScalarConverter::convert("4.2.2f");
	std::cout << std::endl;
	ScalarConverter::convert("--42");
	std::cout << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;
	ScalarConverter::convert("999999999999999999f");
	std::cout << std::endl;
	ScalarConverter::convert("-1");
	return 0; */

		
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
	
}
