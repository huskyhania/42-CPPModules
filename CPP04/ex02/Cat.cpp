/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:14:37 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/06 12:56:32 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original){
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*original.brain);
}

Cat &Cat::operator = (const Cat &original){
	std::cout << "Cat overload assignement operator called" << std::endl;
	if (this != &original)
	{
		delete this->brain;
		type = original.type;
		this->brain = new Brain(*original.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const {
	std::cout << "MIAU MIAU" << std::endl;
}
