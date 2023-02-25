#include "Cast.hpp"

Cast::Cast()
{
	this->ch = 0;
	this->check = false;
	this->argv = 0;
}

Cast::~Cast()
{
}

bool Cast::isBetweenIntLimits(const char* str)
{
    char *endptr;
    long num = strtol(str, &endptr, 10);
	if (endptr == str || *endptr != '\0')
	{
		printf("endptr:%s\n", endptr);
		printf("*end:%c\n", *endptr);
        if (num < INT_MIN || num > INT_MAX)
			return false;
	}
    return num >= INT_MIN && num <= INT_MAX;
}

void	Cast::setChar(char *argv)
{
	int x;
	if (strlen(argv) == 1 && !isdigit(argv[0]))
		this->ch = argv[0];
	else if (isBetweenIntLimits(argv))
	{
		x = atoi(argv);
		if (isprint(x))
			this->ch = x;
		else if (x < 32 && x >= 0)
			this->ch = 1;
	}
}

void	Cast::setInt(char *argv)
{
	int x;
	if (isBetweenIntLimits(argv))
	{
		x = atoi(argv);
		if (x <= INT_MAX && x >= INT_MIN)
		{
			this->in = x;
			this->check = true;
		}
	}
}

char	Cast::getChar() const
{
	if (!this->ch)
		std::cout << "impossible" << std::endl;
	else if (this->ch == 1)
		std::cout << "Non displayable" << std::endl;
	return(this->ch);
}

string	Cast::getInt() const
{
	if (this->check == true)
		return (std::to_string(this->in));
	else
		return("impossible");
}