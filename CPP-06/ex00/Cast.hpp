#ifndef CAST_HPP
#define CAST_HPP

#include <iostream>
#include <limits.h>


using std::	string;
using std:: endl;
using std:: cout;

class Cast
{
private:
	char	ch;
	int		in;
	bool	check;
	int		argv;
	//float	fl;
	//double	db;
public:
	Cast();
	~Cast();
	//setters
	void	setChar(char *argv);
	void	setInt(char	*argv);
	//getters
	char	getChar() const;
	string	getInt() const;
	bool isBetweenIntLimits(const char* str);
};


#endif