#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <utility>
#include <cmath>

bool		is_valid_date(const std::string& date);
std::string	is_valid_value(const std::string& value);
bool		file_check(const std::string fileName, std::ifstream &file);
void		mark_invalid_input(std::vector<std::pair<std::string, std::string> > &_v);
bool		fill_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_v);
void		fill_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData);
int			find_same_date_indx(const std::string& targetDate, const std::vector<std::pair<std::string, double> >& _vData);
void		print_and_handle(const std::vector<std::pair<std::string, std::string> > &_v, const std::vector<std::pair<std::string, double> > &_vData);

#endif