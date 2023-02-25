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
	int i;

	i = 0;
    long num = strtol(str, &endptr, 10);
	if (endptr == str || *endptr != '\0')
	{
        if (num < INT_MIN || num > INT_MAX)
			return false;
		else if (endptr[0] == '.')
			i++;
		while (endptr[i])
		{
			if (!isdigit(endptr[i]))
			{
				if (endptr[i] == 'f' && endptr[i + 1] == '\0')
					break;
				return false;
			}
			i++;
		}
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

void	Cast::setFloat(char *argv)
{
	char *p_end;
	double val;
	val = strtod(argv, &p_end);
	if (*p_end != '\0' && *p_end != 'f')
		this->check  = false;
	else
		this->fl = argv;
}

char	Cast::getChar() const
{
	if (!this->ch)
		std::cout << "impossible";
	else if (this->ch == 1)
		std::cout << "Non displayable";
	return(this->ch);
}

string	Cast::getInt() const
{
	if (this->check == true)
		return (std::to_string(this->in));
	else
		return("impossible");
}

string	Cast::getFloat() const
{
	if (this->check == true)
	{
		return (this->fl);
	}
	return ("false");
}