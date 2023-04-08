/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:28 by aoner             #+#    #+#             */
/*   Updated: 2023/04/08 21:01:30 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	std::cout << "\ntest int" << std::endl;
	int a = 2;
	int b = 3;
	::swap<int>( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "\ntest string " << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "\ntest float" << std::endl;
	float a1 = 3.46;
	float b1 = 2;
	::swap(a1,b1);
	std::cout << "a = " << a1 << ", b = " << b1 << std::endl;
	::swap(a1,b1);
	std::cout << "a = " << a1 << ", b = " << b1 << std::endl;

	double a2 = 3.14;
	double b2 = 2.71828;
	std::cout << "\ntest double" << std::endl;
	::swap(a2,b2);
	std::cout << "a = " << a2 << ", b = " << b2 << std::endl;
	std::cout << "min( a, b ) = " << ::min( a2, b2 ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a2, b2 ) << std::endl;
	return 0;
}
