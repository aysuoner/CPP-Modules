#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

class BitcoinExchange
{
private:
	std::string _fileName;
public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();

	void	set_fileName(std::string argv);
	void	file_ctrl(std::vector<std::string> &_v);
};

#endif