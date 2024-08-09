#include <iostream>
#include "Zombie.hpp"

int	main(){
	int	numOfZombies = 0;
	std::cout << "Creating new ZombieHorde" << std::endl;
	std::cout << "Input the number of Zombies you want to create: ";
	std::cin >> numOfZombies;

	Zombie *zombies = zombieHorde(numOfZombies, "Zombie");
	for (int i = 0; i < numOfZombies; i++){
		zombies[i].announce();
		if (i + 1 < numOfZombies)
			zombies[i + 1].setName("weakZombie" + std::to_string(i + 1));
	}
	delete [] zombies;

	return (0);
}
