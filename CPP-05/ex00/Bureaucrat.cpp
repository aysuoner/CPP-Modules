/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:23:34 by aoner             #+#    #+#             */
/*   Updated: 2023/02/06 22:24:40 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//constructors
Bureaucrat::Bureaucrat(): name(""), grade(0) {}

/* Class içinde tanımlanan name const olarak tanımlanmıştır.
Bu da değişkenin değerinin class dışında değiştirilmemesinin garanti edilmesini amaçlar.
&name olarak gönderilmesi ile veri transferinde daha verimli bir yapı kullanılmış olur çünkü bu şekilde adresini işaret ediyoruz
ve kopyasının oluşturulmasını ve onun üzerinde değişiklik yapılmasını engellemiş oluyoruz.
*/
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		Bureaucrat::GradeTooLowException;
	else if (grade > 150)
		Bureaucrat::GradeTooHighException;
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_obj): name(old_obj.name), grade(old_obj.grade)
{
	
}


//operator overloaded
/* ğer name değişkeni const olarak işaretlenmişse ve name değerinin değiştirilmemesi garanti edilmişse,
copy assignment operator fonksiyonunda name = other.name şeklinde bir satır yazmanız gerekmez.
Zaten garanti edilen bir değerin değiştirilmesi yanlış olur ve bu durum hatalı kod yapısına neden olabilir.
const olarak işaretlenmişse bu durumda, name değişkeninin değeri copy assignment operator fonksiyonu çağrılmadan
önce verilmiş olan değer ile aynı kalır ve değiştirilemez.
*/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &old_obj)
{
	if (this == &old_obj)
		return *this;
	this->grade = old_obj.grade;
	return *this;
}


Bureaucrat::~Bureaucrat()
{
}

/*Const türde bir değişkenin değeri değiştirilemez
bu nedenle fonksiyonun dışında bu değişkeni kullanmak için
const referansı kullanmak daha verimlidir.
 Bu tanımlama, fonksiyonun döndürdüğü değerin bellekte referans olarak
 kullanılmasını sağlar. Bunun sonucu, fonksiyon döndürmüş olduğu değerin
 herhangi bir şekilde değiştirilmemesi garanti edilir ve bu değerin verileri
 bellekte bir kez tanımlanması yeterlidir.*/
const std::string &Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
{
	return(this->grade);
}
