/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:14:37 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/05 20:14:46 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &original){
	std::cout << "Cat overload assignement operator called" << std::endl;
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "MIAU MIAU" << std::endl;
}
