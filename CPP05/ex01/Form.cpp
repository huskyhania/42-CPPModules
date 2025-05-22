/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:39:21 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/22 18:39:28 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(100), _execGrade(10){
	//std::cout << "form default constructor called" << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int signGrade, const int execGrade)
	: _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade){
		//std::cout << "parameter constructor called" << std::endl;
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		else if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
}

Form::Form(const Form &original) : _name(original._name), _isSigned(original._isSigned), 
	_signGrade(original._signGrade), _execGrade(original._execGrade){
	std::cout << "copy constructor called" << std::endl;
}

Form &Form::operator = (const Form &original){
	if (this != &original)
	{
		_isSigned = original._isSigned;
	}
	return (*this);
}

Form::~Form(){
	//std::cout << "form destructor called" << std::endl;
}

const std::string Form::getName() const{
	return _name;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

int Form::getSignGrade() const{
	return _signGrade;
}

int Form::getExecGrade() const{
	return _execGrade;
}

void Form::beSigned(Bureaucrat &clerk){
	if (this->_isSigned){
		throw AlreadySignedException();
	}
	if (clerk.getGrade() > this->_signGrade){
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "the grade is too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "the grade is too low";
}

const char* Form::AlreadySignedException::what() const throw(){
	return "the form was previously signed";
}

std::ostream &operator<<(std::ostream &outstream, Form &f1){
	outstream << "form name: " << f1.getName()
	<< " signature state: " << f1.getIsSigned() 
	<< " signing grade: " << f1.getSignGrade()
	<< " execution grade: " << f1.getExecGrade() << std::endl; 
	return outstream;
}