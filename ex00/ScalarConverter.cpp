/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 23:23:21 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/27 21:47:52 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cerrno>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str)
{
	bool isPseudo = false;
	std::string pseudoLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (str == pseudoLiterals[i])
		{
			isPseudo = true;
			break;
		}
	}

	double dVal = 0.0;

	if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
	{
		dVal = static_cast<double>(str[0]);
	}
	else
	{
		char* endptr;
		dVal = std::strtod(str.c_str(), &endptr);

		if (!isPseudo && endptr == str.c_str())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	std::cout << "char: ";
	if (isPseudo || dVal < std::numeric_limits<char>::min() || dVal > std::numeric_limits<char>::max() || dVal != dVal)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(dVal);
		if(std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (isPseudo || dVal < std::numeric_limits<char>::min() || dVal > std::numeric_limits<char>::max() || dVal != dVal)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(dVal) << std::endl;
	}

	std::cout << "float: ";

	float fVal = static_cast<float>(dVal);

	if (!isPseudo && (dVal > std::numeric_limits<float>::max() || dVal < -std::numeric_limits<float>::max()))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << fVal;
		if (fVal == static_cast<int>(fVal) && fVal < 1e6 && fVal > -1e6)
		{
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}

	std::cout << "double: ";
	std::cout << dVal;
	if (dVal == static_cast<int>(dVal) && dVal < 1e6 && dVal > -1e6)
	{
		std::cout << ".0";
	}
	std::cout << std::endl;
}
