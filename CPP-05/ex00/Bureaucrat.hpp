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

	//public methods
	void        incrementGrade();
    void        decrementGrade();

	//exception classes
	class GradeTooLowException: public std::exception
	{
  		public:
    		virtual const char* what() const _NOEXCEPT
    		{
        		return "Grade too low";
    		}
	};

	class GradeTooHighException: public std::exception
	{
		public:
    		virtual const char* what() const _NOEXCEPT
    		{
        		return "Grade to high";
    		}
	};
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& other);

#endif