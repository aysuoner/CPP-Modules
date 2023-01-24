/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:43:28 by aoner             #+#    #+#             */
/*   Updated: 2023/01/24 15:24:58 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */

int	main(void)
{
	Fixed a(9.3009f);
	Fixed b;

	b = Fixed(9.2901f);

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
	if (a == b)
		std::cout << "a = b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	return 0;
}