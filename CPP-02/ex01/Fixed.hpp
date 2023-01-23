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
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int a);
	Fixed(const float a);
	~Fixed();
	Fixed	&operator=(const Fixed &other);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream& out, const Fixed &other);

#endif


//bir floating numberı bir fixed number'a dönüştürmek için floating point number'ı çarparız