#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	//referene test
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	//pointer test
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	//test for nullptr
	{
		HumanB brian("Brian");
		brian.attack();
		Weapon gun = Weapon("big ass gun");
		brian.setWeapon(gun);
		brian.attack();
	}
	return (0);
}
