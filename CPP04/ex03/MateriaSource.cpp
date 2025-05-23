/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:59 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/06 17:26:13 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
    {
        placeholder[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource &original){
    for (int i = 0; i < 4; i++){
        if (original.placeholder[i]){
            placeholder[i] = original.placeholder[i]->clone();
        }
        else{
            placeholder[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &original){
    if (this != &original){
        for (int i = 0; i < 4; i++){
            if (placeholder[i]){
                delete placeholder[i];
                placeholder[i] = nullptr;
            }
        }
        for (int i = 0; i < 4; i++){
            if (original.placeholder[i]){
                placeholder[i] = original.placeholder[i]->clone();
            }
            else{
                placeholder[i] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++){
        if (placeholder[i] != nullptr){
            delete placeholder[i];
            placeholder[i] = nullptr;
        }
    }
}

void MateriaSource::learnMateria(AMateria* toCheck){
    if (toCheck == nullptr){
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (placeholder[i] == nullptr){
            placeholder[i] = toCheck;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type){
    for (int i = 0; i < 4; i++){
        if (placeholder[i] != nullptr && placeholder[i]->getType() == type){
            return (placeholder[i]->clone());
        }
    }
    return 0;
}
