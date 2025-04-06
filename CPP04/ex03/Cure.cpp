/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:25:41 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/06 15:39:55 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &original) : AMateria(original.type){
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &original){
	if (this != &original){
		AMateria::operator=(original);
	}
	return *this;
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const{
	return (new Cure);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
