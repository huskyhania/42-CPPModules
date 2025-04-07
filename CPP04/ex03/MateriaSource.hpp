#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
	private:
		AMateria *placeholder[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& original);
		MateriaSource& operator=(const MateriaSource& original);
		~MateriaSource();
		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif
