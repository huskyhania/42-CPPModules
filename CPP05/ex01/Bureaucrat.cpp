/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:14:06 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/19 18:15:48 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(50) {
	//std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	//std::cout << "parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) : _name(original._name), _grade(original._grade){
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &original){
	if (this != &original)
	{
		_grade = original._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	//std::cout << "destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "The grade is too low";
}

const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade(){
	if (_grade <= 1)
		throw GradeTooHighException();
	else{ 
		_grade--;
		std::cout << "incrementing bureaucrat's grade" << std::endl;
	}
}

void Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw GradeTooLowException();
	else{
		_grade++;
		std::cout << "decrementing bureaucrat's grade" << std::endl;
	}
}

void Bureaucrat::signForm(Form &f1){
	try{
		f1.beSigned(*this);
		std::cout << this->_name << " signed form " << f1.getName() << std::endl; 
	}
	catch(std::exception &err){
		std::cout << this->_name << " couldn't sign form " << f1.getName() 
		<< " because " << err.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &outstream, Bureaucrat &buro){
	outstream << buro.getName() << ", bureaucrat grade " << buro.getGrade() << "." << std::endl;
	return outstream;
}