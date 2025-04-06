/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:12:25 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/06 15:13:16 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &original) : AMateria(original.type){
	std::cout << "Ice copy constructor called" << std::endl;
}
	
Ice &Ice::operator=(const Ice &original){
	if (this != &original){
		AMateria::operator=(original);
	}
	return *this;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const{
	return (new Ice);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
