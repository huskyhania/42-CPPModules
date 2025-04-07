#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "Character.hpp"

//this is an abstract class, = 0 makes a method pure virtual one
//NOT INSTANTIABLE!
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
