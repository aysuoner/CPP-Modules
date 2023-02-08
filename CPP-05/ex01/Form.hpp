#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const		std::string name;
	bool		is_signed;
	const int	sign_grade;
	const int	exec_grade;
public:
	//constructor
	Form(void);
	Form(const std::string &name, int sign_grade , int exec_grade);
	Form(const Form &old_obj);
	
	//Destrcutor
	~Form();

	//Operator Overload
	Form	&operator=(const Form &old_obj);

	//getter
	const std::string	getName(void)const;
	bool				getIsSigned(void)const;
	int					getSignGrade(void)const;
	int					getExecGrade(void)const;

	//Public Method
	/* //burokratın imzalama yetkisi varsa formu
	imzalandı olarak değiştiren bir fonk. */
	void	beSigned(const Bureaucrat &b);

	//Exeption
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char * what()const _NOEXCEPT;
	};

	class GradeTooLowException: public std::exception
	{
  		public:
    		virtual const char* what()const _NOEXCEPT;
	};

};

//Ostream operator
std::ostream& operator<<(std::ostream& out, const Form& other);

#endif