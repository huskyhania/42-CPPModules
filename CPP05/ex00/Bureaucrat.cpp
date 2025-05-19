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

Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(50) {}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: _name(name), _grade(grade){}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &original){
	if (this != &original)
	{
		_grade = original._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void incrementGrade();
//if temp <= 0, throw exception

void decrementGrade();
//if temp > 150, throw exception