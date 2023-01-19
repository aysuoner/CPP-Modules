#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
//#include <string.h>

class replace
{
private:
	std::string filename;
	std::string s1;
	std::string s2;
	std::string replace_str;
public:
	//the constructors and destructors
	replace(std::string filnename, std::string s1, std::string s2);
	~replace();
	//setter;
	void	setfilename(std::string filename);
	void	sets1(std::string s1);
	void	sets2(std::string s2);
	void	setreplace_str(std::string replace_str);
	//getter;
	std::string	getfilename() const;
	std::string	gets1() const;
	std::string	gets2() const;
	std::string	getreplace_str() const;	
};

void	ReplaceStringInPlace(std::string& line, const std::string& search,
								const std::string& replace);

#endif