#include "Zombie.hpp"
#include <new>

int	main(void)
{
	Zombie *zmb = newZombie("Jared Heap Boi");
	zmb->announce();
	randomChump("Jay Stack Guy");
	delete(zmb);
	return (0);
}
