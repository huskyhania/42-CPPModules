#include "Character.hpp"

Character::Character() : name("noName"){
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
}

Character::Character(std::string name) : name(name){
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (inventory[i] != nullptr)
			delete(inventory[i]);
	}
}

Character::Character(const Character &original): name(original.name){
	for (int i = 0; i < 4; i++){
		inventory[i] = (original.inventory[i] != nullptr) ? original.inventory[i] : nullptr;
	}
}

Character &Character::operator=(const Character &original){
	if (this != &original){
		this->~Character();
		new(this) Character(original);
	}
	return (*this);
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (inventory[i] == nullptr){
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (inventory[idx] != nullptr){
		inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target){
	if (inventory[idx] != nullptr){
		inventory[idx]->use(target);
	}
}

std::string const &Character::getName() const{
	return name;
}