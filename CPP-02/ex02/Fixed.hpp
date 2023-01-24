#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixed_num;
	static const int	fract_bit = 8;
public:
	//orthodox canonical form
	Fixed();
	Fixed(const int a);
	Fixed(const float a);
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	~Fixed();

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits() const;
	void	setRawBits(int const raw);

	//arithmetic operators
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const	Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	//comparison operators
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	bool	operator<(const Fixed &other)  const;
	bool	operator>(const Fixed &other)  const;
	bool	operator<=(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;

	//Increment/Decrement operators
	Fixed	operator++(int); //postfix;
	Fixed	operator--(int); //postfix
	Fixed	operator++(void);
	Fixed	operator--(void);








	















/* 	Fixed	&operator++(void);	// prefix
    Fixed   operator++(int);	// postfix
    Fixed	&operator--(void);	// prefix
    Fixed   operator--(int);	// postfix */
};

std::ostream	&operator<<(std::ostream& out, const Fixed &other);

#endif
