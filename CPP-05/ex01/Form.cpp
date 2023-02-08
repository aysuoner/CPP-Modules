/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:25:45 by aoner             #+#    #+#             */
/*   Updated: 2023/02/08 22:17:50 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructor
Form::Form(void): name("default"), is_signed(false), sign_grade(1), exec_grade(1){
}

Form::Form(const std::string &name, int sign_grade , int exec_grade)
	:name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	this->is_signed = false;
}

Form::Form(const Form &old_obj)
	: name(old_obj.getName() + "_copy"), is_signed(false), sign_grade(old_obj.getSignGrade()), exec_grade(old_obj.getExecGrade()) 
{
	std::cout << "Form Copy Constructor has been called" << std::endl;
	*this = old_obj;
}

//Dectructor
Form::~Form()
{
	std::cout << "Form Destructor for " << this->getName() << " called" << std::endl;
}

//Operator Overload
/*is_signed'ı neden bu şekilde eşitledik diğer değerleri değil???*/
Form	&Form::operator=(const Form &old_obj)
{
	std::cout << "Form copy assignment operator has been called" << std::endl;
    this->is_signed = old_obj.getIsSigned();
    return *this;
}

//Getter
const std::string	Form::getName(void)const
{
	return(this->name);
}

bool				Form::getIsSigned(void)const
{
	return(is_signed);
}

int					Form::getSignGrade(void)const
{
	return(this->sign_grade);
}

int					Form::getExecGrade(void)const
{
	return(this->exec_grade);
}

//public method
/*burokratın imzalama yetkisi varsa
formu imzalandı olarak değiştiren bir fonk*/
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->sign_grade)
 	{
		this->is_signed = true;
		std::cout << this->getName() << " Form was signed by " << b.getName() << std::endl;
 	}
 	else
		throw Form::GradeTooLowException();
}

//exception
const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high\n");
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade too low\n");
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	out     	<< other.getName()
				<< " Form. Grade to sign: "
				<< other.getSignGrade()
				<< ". Grade to execute: "
				<< other.getExecGrade()
				<< " Is signed: ";
	if (other.getIsSigned())
		out << "Yes." << std::endl;
	else
		out << "No." << std::endl;
	return (out);
}