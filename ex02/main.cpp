/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 22:13:30 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/28 22:46:22 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate(void)
{
	int	r = std::rand() % 3;

	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer identifies type: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer identifies type: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer identifies type: C" << std::endl;
	else
		std::cout << "Pointer identifies type: Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference identifies type: A" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference identifies type: B" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference identifies type: C" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "Reference identifies type: Unknown" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "--- Test " << i + 1 << " ---" << std::endl;
		Base* instance = generate();

		identify(instance);
		identify(*instance);

		delete instance;
		std::cout << std::endl;
	}
	return (0);
}
