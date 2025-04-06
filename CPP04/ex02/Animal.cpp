/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:22:51 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/06 14:19:24 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("general") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal parameter construcor called" << std::endl;
}

Animal::Animal(const Animal &original) : type(original.type){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator = (const Animal &original){
	std::cout << "Animal overload assignment operator called" << std::endl;
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}


std::string Animal::getType() const {
	return type;
}
