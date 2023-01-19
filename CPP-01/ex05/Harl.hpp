#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

//Bu alıştırmanın amacı, üye işlevlerine işaretçiler kullanmaktır. if/else if kullanmadan. 
class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl(/* args */);
	~Harl();
	void    complain( std::string level); //parametre olarak gönderilen 4 levele bağlı olarak 4 members func'ı çağıran public member func.
};

#endif