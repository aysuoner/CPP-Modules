/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:12 by aoner             #+#    #+#             */
/*   Updated: 2023/04/30 17:51:02 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string	is_valid_value(const std::string& input)
{
	if (input.empty())
		return "false";
	else
	{
		char* endptr = NULL;
		long l = std::strtol(input.c_str(), &endptr, 0);
		if (*endptr == '\0')
		{
			if (l > 1000 || l < 0)
				return "false";
			return "int";
		}
		else
		{
			endptr = NULL;
			float f = std::strtof(input.c_str(), &endptr);
			if (*endptr == '\0' || (endptr[0] == 'f' && endptr[1] == 0))
			{
				if (f > 1000 || f < 0)
					return "false";
				return "float";
			}
			else
				return "false";
		}
	}
}

bool is_valid_date(const std::string& date)
{
	// Date format should be "yyyy-mm-dd"
    if (date.size() != 10) {
        return false;
    }
    // Check year
    int year = std::stoi(date.substr(0, 4));
    if (year < 0 || year > 9999) {
        return false;
    }
    // Check month
    int month = std::stoi(date.substr(5, 2));
    if (month < 1 || month > 12) {
        return false;
    }
    // Check day
    int day = std::stoi(date.substr(8, 2));
    if (day < 1 || day > 31) {
        return false;
    }
    // Check if day is valid for the given month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        int max_day = 28;
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            max_day = 29;
        }
        if (day > max_day) {
            return false;
        }
    }
    return true;
}
