#include "Zombie.hpp"
#include <new>

int	main(void)
{
	randomChump("Jay Stack Guy");
	Zombie *zmb = newZombie("Jared Heap Boi");
	if (!zmb)
		return 1;
	zmb->announce();
	delete(zmb);
	return (0);
}
