#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>  //ofstream - ifstream //getline()
#include <utility> //std::pair<>
#include <algorithm>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cmath>

bool		is_valid_date(const std::string& date);
std::string	is_valid_value(const std::string& value);
bool		file_check(const std::string fileName, std::ifstream &file);
void		mark_invalid_input(std::vector<std::pair<std::string, std::string> > &_v);
bool		fill_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_v);
void		fill_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData);
int			binary_search(const std::string& targetDate, const std::vector<std::pair<std::string, double> >& _vData);
void		print_and_handle(const std::vector<std::pair<std::string, std::string> > &_v, const std::vector<std::pair<std::string, double> > &_vData);

#endif