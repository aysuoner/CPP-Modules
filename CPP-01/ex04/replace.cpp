/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:37:23 by aoner             #+#    #+#             */
/*   Updated: 2023/01/19 10:49:06 by aoner            ###   ########.fr       */
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
	this->replace_str = "";
}
//deconst
replace::~replace()
{
}

//setters bunların içinde kontrol yap:
void replace::setfilename(std::string filename)
{
   std::ifstream ifile;
   ifile.open(filename);
   if(ifile)
   {
		this->filename = filename + ".replace";
   }
   else
   {
		std::cout <<"This file doesn't exist!" << std::endl;
		exit(EXIT_FAILURE);
   }
}

void replace::sets2(std::string s2)
{
	this->s2 = s2;
}
void replace::setreplace_str(std::string replace_str)
{
	this->replace_str = replace_str;
}

void replace::sets1(std::string s1)
{
	this->s1 = s1;
}

//getters
std::string replace::getfilename() const
{
	return filename;
}

std::string replace::gets1() const
{
	return s1;
}

std::string replace::gets2() const
{
	return s2;
}

std::string replace::getreplace_str() const
{
	return replace_str;
}

