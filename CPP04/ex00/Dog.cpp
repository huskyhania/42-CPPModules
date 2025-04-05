/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:14:52 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/05 20:15:01 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &original){
	std::cout << "Dog overload assignement operator called" << std::endl;
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "HAU HAU" << std::endl;
}

