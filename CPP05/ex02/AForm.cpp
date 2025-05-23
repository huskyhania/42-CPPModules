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

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(100), _execGrade(10){
	//std::cout << "form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, const int signGrade, const int execGrade)
	: _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade){
		//std::cout << "parameter constructor called" << std::endl;
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		else if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
}

AForm::AForm(const AForm &original) : _name(original._name), _isSigned(original._isSigned), 
	_signGrade(original._signGrade), _execGrade(original._execGrade){
	std::cout << "copy constructor called" << std::endl;
}

AForm &AForm::operator = (const AForm &original){
	if (this != &original)
	{
		_isSigned = original._isSigned;
	}
	return (*this);
}

AForm::~AForm(){
	//std::cout << "form destructor called" << std::endl;
}

const std::string AForm::getName() const{
	return _name;
}

bool AForm::getIsSigned() const{
	return _isSigned;
}

int AForm::getSignGrade() const{
	return _signGrade;
}

int AForm::getExecGrade() const{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat &clerk){
	if (this->_isSigned){
		throw AlreadySignedException();
	}
	if (clerk.getGrade() > this->_signGrade){
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "the grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "the grade is too low";
}

const char* AForm::AlreadySignedException::what() const throw(){
	return "the form was previously signed";
}

const char* AForm::NotSignedException::what() const throw(){
	return "the form wasn't signed";
}

std::ostream &operator<<(std::ostream &outstream, AForm &f1){
	outstream << "form name: " << f1.getName()
	<< " signature state: " << f1.getIsSigned() 
	<< " signing grade: " << f1.getSignGrade()
	<< " execution grade: " << f1.getExecGrade() << std::endl; 
	return outstream;
}