#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <new>

class Cure: public AMateria{
	public:
		Cure();
		Cure(const Cure &original);
		Cure &operator=(const Cure &original);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
