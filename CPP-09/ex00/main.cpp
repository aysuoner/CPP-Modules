/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:39 by aoner             #+#    #+#             */
/*   Updated: 2023/04/30 22:43:52 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	multiple_values(std::vector<std::pair<std::string, std::string> > &_v, std::vector<std::pair<std::string, double> > &_vData)
{
	
}

void	print_and_handle(std::vector<std::pair<std::string, std::string> > &_v, std::vector<std::pair<std::string, double> > &_vData)
{
	for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		if (it->first == "-1"){
			std::cout << "Error: invalid date" << std::endl;
		} else if (it->second == "-1"){
			std::cout << "Error: invalid value" << std::endl;	
		}
		else
		{
			multiple_values(_v, _vData);
			std::cout << it->first << " => " << strtod(it->second.c_str(), NULL) << std::endl;
		}
	}
}

void	input_valid_check(std::vector<std::pair<std::string, std::string> > &_v)
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

void	fill_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData)
{
	std::string date;
	std::string val;
	double		btc;
	std::string line;
	size_t pos;
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

void	fill_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_v)
{
	std::string date;
	std::string val;
	std::string line;
	size_t pos;
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
	file.close();
}

bool	file_check(const std::string fileName, std::ifstream &file)
{
    file.open(fileName.c_str());
    if (!file.is_open())
    {
        std::cout << "File cannot be opened" << std::endl;
		file.close();
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Arguments too few";
		exit(EXIT_FAILURE);
	}
	else
	{
    	std::ifstream file;
		std::vector<std::pair<std::string, std::string> > _v;
		std::vector<std::pair<std::string, double> > _vData;
        if (!file_check(argv[1], file))
		{
			return (EXIT_FAILURE);
		}
		fill_input(file, _v);
		input_valid_check(_v);
		if (!file_check("data.csv", file))
		{
			return (EXIT_FAILURE);
		}
		fill_data_base(file, _vData);
		print_and_handle(_v, _vData);
		
		std::cout << std::endl;
		std::cout << std::endl;
		for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		for (std::vector<std::pair<std::string, double> >::const_iterator it = _vData.begin(); it != _vData.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << std::endl;
		}
	}
}
