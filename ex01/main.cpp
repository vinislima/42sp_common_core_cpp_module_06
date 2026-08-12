/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:33:23 by vinda-si          #+#    #+#             */
/*   Updated: 2026/07/27 22:52:06 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Data	dataObj;
	dataObj.text 	= "Inception M2";
	dataObj.value	= 42;

	std::cout << "Original Pointer: " << &dataObj << std::endl;
	std::cout << "Data: " << dataObj.text << ", " << dataObj.value << std::endl;

	uintptr_t	raw = Serializer::serializer(&dataObj);
	std::cout << "Serialized (unitptr_t): " << raw << std::endl;

	Data*	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Pointer: " << deserialized << std::endl;

	if (deserialized == &dataObj)
	{
		std::cout << "Success: Pointer match!" << std::endl;
		std::cout << "Data: " << deserialized->text << ", " << deserialized->value << std::endl;
	}
	else
	{
		std::cout << "Error: Pointers do not match!" << std::endl;
	}

	return (0);
}
