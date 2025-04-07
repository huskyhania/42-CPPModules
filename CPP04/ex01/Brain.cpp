/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:01:47 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/07 15:31:28 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &original){
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = original.ideas[i];
	}
}

Brain &Brain::operator = (const Brain &original){
	std::cout << "Brain overload assignement operator called" << std::endl;
	if (this != &original){
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = original.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int index, std::string idea){
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	return ;
}

std::string	Brain::getIdea(int index) const{
	return (index >= 0 && index < 100) ? ideas[index] : "???";
}
