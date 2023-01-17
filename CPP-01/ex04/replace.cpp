/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:37:23 by aoner             #+#    #+#             */
/*   Updated: 2023/01/17 18:37:20 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <fstream>
//const
replace::replace(std::string filnename, std::string s1, std::string s2)
{
	this->filename = filnename;
	this->s1 = s1;
	this->s2 = s2;
}
//deconst
replace::~replace()
{
}

//setters bunların içinde kontrol yap:
void replace::setfilename(std::string filename)
{
	this->filename = filename;
	std::ofstream outfile (this->getfilename());
	outfile << "my text here!" << std::endl;
	outfile.close();
}

void replace::sets2(std::string s2)
{
	this->s2 = s2;
}

void replace::sets1(std::string s1)
{
	this->s1 = s1;
}

//getters bunları const yap
std::string replace::getfilename()
{
	return filename;
}

std::string replace::gets1()
{
	return s1;
}

std::string replace::gets2()
{
	return s2;
}

