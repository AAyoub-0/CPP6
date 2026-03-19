/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 02:21:32 by aboumall          #+#    #+#             */
/*   Updated: 2026/03/20 01:39:03 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	(void)argc; // Suppress unused parameter warning
	(void)argv; // Suppress unused parameter warning

	ScalarConverter::convert("0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("42.0");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("42.2");
	ScalarConverter::convert("-42.2");
	ScalarConverter::convert("42.2f");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("invalid");
	ScalarConverter::convert("42.2ff");
	ScalarConverter::convert("4.2.2f");
	ScalarConverter::convert("--42");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("");
	ScalarConverter::convert("999999999999999999f");
	ScalarConverter::convert("999999999999999999999999999999999999999999.9");
	ScalarConverter::convert("-1");
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}