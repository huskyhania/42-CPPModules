#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

//make sure it's orthodox cannonical
class MateriaSource: public IMateriaSource{
	private:
		AMateria *placeholder[4];
	public:
		MateriaSource();
		~MateriaSource();
		//copy constructot
		//asignmenet operator
		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif
