#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <new>

class Ice: public AMateria{
	public:
		Ice();
		Ice(const Ice &original);
		Ice &operator=(const Ice &original);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
