#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter{
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &original);
		~Character();
		Character &operator=(const Character &original);
		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override; 		
};

#endif
