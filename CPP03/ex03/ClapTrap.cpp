#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("No name"), hitPoints(startHitPoints), energyPoints(startEnergyPoints), attackDamage(startAttackDamage)
{
	std::cout << "ClapTrap default constructor called for " << name << std::endl << std::endl;
	std::cout << "values are: " << this->hitPoints << " " << this->energyPoints << " " << this->attackDamage << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(startHitPoints), energyPoints(startEnergyPoints), attackDamage(startAttackDamage)
{
	std::cout << std::endl << "ClapTrap parameter constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original) : name(original.name), hitPoints(original.hitPoints), energyPoints(original.energyPoints),
	attackDamage(original.attackDamage)
{
	std::cout << std::endl << "ClapTrap copy constructor called for " << name << std::endl << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &original)
{
	std::cout << "ClapTrap overload assignment operator called" << std::endl << std::endl;
	if (this != &original)
	{
		name = original.name;
		hitPoints = original.hitPoints;
		energyPoints = original.energyPoints;
		attackDamage = original.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack due to lack of hit points" << std::endl;
	}
	else if (energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target 
			<< ", causing " << attackDamage << " points of damage" << std::endl;
			energyPoints--;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack due to lack of energy" << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0){
		std::cout << "ClapTrap " << name << " is dead already and cannot receive anymore damage " << std::endl;
	}
	else if (hitPoints > 0 && amount > 0){
		hitPoints = (hitPoints > amount) ? (hitPoints - amount) : 0;
		//works same as: 
		//if (hitPoints > 0) 
		//	hitPoints = hitPoints - amount 
		//else 
		//hitPoints = 0;
		std::cout << "ClapTrap " << name << " has been hit and received " << amount << " damage" << std::endl;
		std::cout << name << " has " << hitPoints << " hit points left" << std::endl;
	}

}

//check hitpoints, increase energy (or not), print result
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0){
		std::cout << "ClapTrap " << name << " is basically dead and cannot be repaired" << std::endl; 
	}
	else if (energyPoints == 0){
		std::cout << "ClapTrap " << name << " run out of energy and cannot restore itself" << std::endl;
	}
	else{
		energyPoints--;
		hitPoints = (hitPoints + amount > getStartHitPoints()) ? getStartHitPoints() : hitPoints + amount;
		std::cout << "ClapTrap " << name << " is restored with " << amount << " points and now has " 
			<< hitPoints << " hit points" << std::endl;
	}
}

std::string	ClapTrap::getName() const
{
	return name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

unsigned int ClapTrap::getStartHitPoints() const
{
	return startHitPoints;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}