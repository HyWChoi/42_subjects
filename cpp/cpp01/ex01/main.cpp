#include <iostream>
#include "Zombie.hpp"

int	main(){
	int	numOfZombies = 10;
	std::cout << "Creating new ZombieHorde" << std::endl;

	Zombie *zombies = zombieHorde(numOfZombies, "Zombie");
	for (int i = 0; i < numOfZombies; i++){
		zombies[i].announce();
		if (i + 1 < numOfZombies)
			zombies[i + 1].setName("weakZombie" + std::to_string(i + 1));
	}
	delete [] zombies;

	return (0);
}
