/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:06:58 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 00:07:00 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 0, 25, 5), _target("Luigi"){
	std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", 0, 25, 5), _target(target){
	std::cout << "Presidential parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original):
	AForm("PresidentialPardonForm", 0, 25, 5), _target(original.getTarget())
{
	std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &original){
	if (this != &original)
	{
		this->_target = original.getTarget();
		AForm::operator=(original);
	}
	std::cout << "Presidential assignement operator" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential destructor" << std::endl;
}

const std::string PresidentialPardonForm::getTarget() const{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	std::cout << "Presidential execute called" << std::endl;
	if (!this->getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
