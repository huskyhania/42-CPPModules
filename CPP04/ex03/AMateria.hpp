#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Character.hpp"

class AMateria{
	protected:
		std::string type;	
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &original);
		AMateria &operator=(const AMateria &original);
		virtual ~AMateria();

		std::string const & getType() const; // returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
