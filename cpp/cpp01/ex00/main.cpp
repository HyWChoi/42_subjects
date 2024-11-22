#include <iostream>
#include "Zombie.hpp"

int	main(){
	std::cout << "Creating a new Zombie" << std::endl;
	Zombie *zombie = newZombie("Zombie");
	zombie->announce();
	delete zombie;

	std::cout << "Creating a random Zombie" << std::endl;
	randomChump("RandomZombie");

	return (0);
}
