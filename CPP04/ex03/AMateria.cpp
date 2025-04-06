/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:46:27 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/06 15:05:05 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("none"){
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type){
	std::cout << "AMateria parameter constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &original){
	this->type = original.type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &original){
	std::cout << "AMateria overload assignement operator called" << std::endl;
	if (this != &original){
		this->type = original.type;
	}
	//(void) original;
	return *this;
}

void	AMateria::use(ICharacter& target){
	(void)target;
	std::cout << "random thing happening" << std::endl;
}

std::string const &AMateria::getType() const{
	return type;
}
