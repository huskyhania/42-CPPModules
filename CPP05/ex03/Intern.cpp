/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:22:05 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/23 20:44:05 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &original){
	std::cout << "Intern copy constructor" << std::endl;
}

Intern &Intern::operator = (const Intern &original){
	std::cout << "Intern assignement operator" << std::endl;
	return (*this);
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

int chooseReqType(const std::string &name){
	const std::string options[3] = {"shrubbery", "robotomy", "pardon"};
	for (int i = 0; i < 3; i++){
		if (name == options[i])
			return (i + 1); 
	}
	return (0);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target){
	std::cout << "Intern is trying to create a form" << std::endl;
	int type = chooseReqType(name);
	std::cout << type << " --> type" << std::endl;
	switch(type){
		case 1:{
			std::cout << "form chosen: shrubbery" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case 2:{
			std::cout << "form chosen: robotomy" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 3:{
			std::cout << "form chosen: pardon" << std::endl;
			return (new PresidentialPardonForm(target));
		}
		default:{
			std::cout << "this form is not interns' job" << std::endl;
			std::cout << "available options: shrubbery, robotomy, pardon" << std::endl;
			return (nullptr);
		}
	}
}