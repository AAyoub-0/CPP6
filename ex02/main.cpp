/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:54:56 by aboumall          #+#    #+#             */
/*   Updated: 2026/03/24 16:52:10 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	std::srand(std::time(NULL));
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "Generated A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "Generated B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

#include <typeinfo>

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast&) {}
}

int main()
{
	Base* base = generate();
	std::cout << "Identify by pointer: ";
	identify(base);
	std::cout << "Identify by reference: ";
	identify(*base);
	delete base;
	return 0;
}