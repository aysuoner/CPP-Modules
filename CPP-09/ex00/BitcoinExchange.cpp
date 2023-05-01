/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:12 by aoner             #+#    #+#             */
/*   Updated: 2023/05/01 22:50:54 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	file_check(const std::string fileName, std::ifstream &file)
{
    file.open(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: File cannot be opened" << std::endl;
		file.close();
        return false;
    }
    return true;
}

bool	fill_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_v)
{
	std::string	date;
	std::string	val;
	std::string	line;
	size_t		pos;

	while(std::getline(file, line))
	{
		pos = line.find(" | ");
		if (pos != std::string::npos)
		{
        	date = line.substr(0, pos);
        	val = line.substr(pos+3);
        	_v.push_back(std::make_pair(date, val));
        }
		else
		{
			std::string date = line.substr(0, pos);
			_v.push_back(std::make_pair("-1", "-1"));
		}
	}
	if (_v.size() == 0)
		return false;
	file.close();
	return true;
}

void	mark_invalid_input(std::vector<std::pair<std::string, std::string> > &_v)
{
	int i = 0;
	for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		if (is_valid_date(it->first) == false || is_valid_value(it->second) == "false")
		{
			_v[i].first = "-1";
			_v[i].second = "-1";
		}
		i++;
	}
}

bool	is_valid_date(const std::string& date)
{
	// Date format should be "yyyy-mm-dd" //yyy*mm*dd hesaplamıyor?
    if (date.size() != 10) {
        return false;
    }
    // Check year
    int year = std::stoi(date.substr(0, 4));
    if (year < 0 || year > 9999 || date[4] != '-') {
        return false;
    }
    // Check month
    int month = std::stoi(date.substr(5, 2));
    if (month < 1 || month > 12 || date[7] != '-' ) {
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

std::string	is_valid_value(const std::string& value)
{
	if (value.empty())
		return "false";
	else
	{
		char* endptr = NULL;
		long l = std::strtol(value.c_str(), &endptr, 0);
		if (*endptr == '\0')
		{
			if (l > 1000 || l < 0)
				return "false";
			return "int";
		}
		else
		{
			endptr = NULL;
			float f = std::strtof(value.c_str(), &endptr);
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

void	fill_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData)
{
	std::string	date;
	std::string	val;
	std::string	line;
	size_t		pos;
	double		btc;

	while(std::getline(file, line))
	{
		pos = line.find(",");
		if (pos != std::string::npos)
		{
        	date = line.substr(0, pos);
        	val = line.substr(pos+1);
			btc = strtod(val.c_str(), NULL);
        	_vData.push_back(std::make_pair(date, btc));
        }
	}
	file.close();
}

void	print_and_handle(const std::vector<std::pair<std::string, std::string> > &_v, const std::vector<std::pair<std::string, double> > &_vData)
{
	double  multiple;
	int		indx; 
	
	for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		if (it->first == "-1" || it->second == "-1")
		{
			std::cout << "Error: bad input" << std::endl;	
		}
		else
		{
			indx = find_same_date_indx(it->first, _vData);
			multiple = strtod(it->second.c_str(), NULL) * _vData[indx].second;
			std::cout << it->first << " => " << it->second << " = " << multiple << std::endl;
		}
	}
}

int	find_same_date_indx(const std::string& targetDate, const std::vector<std::pair<std::string, double> >& _vData)
{
    int	n = _vData.size();
    int	left = 0;
	int	right = n-1;
	int	mid;
    while (left <= right)
	{
        mid = (left + right) / 2;
        if (_vData[mid].first == targetDate)
		{
            return mid;
        }
		else if (_vData[mid].first < targetDate)
		{
            left = mid + 1;
        }
		else
		{
            right = mid - 1;
        }
    }
    // If the target date is not found, return the index of the nearest lower date
    if (right < 0) {
        return -1; // There is no lower date, return an invalid index
    } else {
        return right;
    }
}




/* bool dateComparator(const std::pair<std::string, double>& lhs, const std::pair<std::string, double>& rhs) {
    return lhs.first < rhs.first;
}


int findNearestLowerDateIndex(const std::vector<std::pair<std::string, double> >& vData, const std::string& date) {
    int index = std::lower_bound(vData.begin(), vData.end(), std::make_pair(date, 0.0), dateComparator) - vData.begin();
    if (index == 0) {
        return -1;
    }
    return index - 1;
}

int	find_same_date_indx(const std::string& targetDate, const std::vector<std::pair<std::string, double> >& _vData)
{
	int index;
	index = std::binary_search(_vData.begin(), _vData.end(), std::make_pair(targetDate, 0.0), dateComparator);
	if (index)
	{
		return (index);
    } else
	{
        int nearestIndex = findNearestLowerDateIndex(_vData, targetDate);
		return (nearestIndex);
	}
} */
