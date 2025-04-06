#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

//make sure it's orthodox cannonical
class MateriaSource: public IMateriaSource{
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const & type) override;
}
