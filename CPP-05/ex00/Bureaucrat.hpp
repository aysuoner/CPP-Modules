#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	//constructor
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &old_obj);

	//overloaded operator
	Bureaucrat &operator=(const Bureaucrat &old_obj);

	//destructor
	~Bureaucrat();

	//setter
	void	setGrade(int grade);

	//getter
	const std::string	&getName() const;
	int					getGrade() const;

	//public method
	void        incrementGrade();
    void        decrementGrade();

	//exception class
	class GradeTooLowException: public std::exception
	{
  		public:
    		virtual const char* what() const _NOEXCEPT;
	};

	class GradeTooHighException: public std::exception
	{
		public:
    		virtual const char* what() const _NOEXCEPT;
	};
};

//ostream overload
std::ostream&   operator<<(std::ostream& out, const Bureaucrat& other);

#endif