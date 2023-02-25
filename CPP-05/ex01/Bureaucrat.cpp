/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:23:34 by aoner             #+#    #+#             */
/*   Updated: 2023/02/23 15:22:43 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(): name("default"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_obj): name(old_obj.name + "_copy"), grade(old_obj.grade)
{
	std::cout << "Bureaucrat Copy Constructor has been called" << std::endl;
	*this = old_obj;
}

//Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor for " << this->getName() << " called" << std::endl;
}

//Operator overloaded
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &old_obj)
{
	std::cout << "Bureaucrat Copy Assignment Operator has been called" << std::endl;
	if (this == &old_obj)
		return *this;
	this->grade = old_obj.getGrade();
	return *this;
}

//Setter
void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

//Getter
const std::string &Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
{
	return(this->grade);
}

//Exceptions
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade too low\n");
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade too high\n");
}

//Public method
void    Bureaucrat::incrementGrade()
{
	this->setGrade(this->grade - 1);
}

void    Bureaucrat::decrementGrade()
{
    this->setGrade(this->grade + 1);
}

void	Bureaucrat::signForm(Form &form)
{
    if (form.getIsSigned())
        std::cout << this->name 
        << " signed " 
        << form.getName() 
        << std::endl;
    else
        std::cout << this->name
                  << " couldn't sign "
                  << form.getName()
                  << " because Grade is too low"
                  << std::endl;
}

//Ostream overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return out;
}