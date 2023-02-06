#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	//constructors
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &old_obj);

	//overloaded operator
	Bureaucrat &operator=(const Bureaucrat &old_obj);

	//destructor
	~Bureaucrat();

	//getters
	const std::string	&getName() const;
	int					getGrade() const;

	class GradeTooLowException: public std::exception
	{
  		public:
    		virtual const char* what() const throw()
    		{
        		return "tooolow\n";
    		}
	};

	class GradeTooHighException: public std::exception
	{
		public:
    		virtual const char* what() const throw()
    		{
        		return "tooo high\n";
    		}
	};

};


#endif