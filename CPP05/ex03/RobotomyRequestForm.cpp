/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:04:20 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 00:04:21 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 0, 72, 45), _target("Robotomy"){
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 0, 72, 45), _target(target){
	std::cout << "Robotomy parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original):
	AForm("RobotomyRequestForm", 0, 72, 45), _target(original.getTarget())
{
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &original){
	if (this != &original)
	{
		this->_target = original.getTarget();
		AForm::operator=(original);
	}
	std::cout << "Robotomy assignement operator" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy destructor" << std::endl;
}

const std::string RobotomyRequestForm::getTarget() const{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	std::cout << "Robotomy execute called" << std::endl;
	if (!this->getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << "BRRRR... DRRR... SHHH..." << std::endl;
	srand(time(NULL));
	if (rand()%100 %2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}

