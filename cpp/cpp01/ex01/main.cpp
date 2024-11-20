#include <iostream>
#include "Zombie.hpp"

int main() {
    int numOfZombies;
    
    std::cout << "Enter the number of zombies to create: ";
    std::cin >> numOfZombies;
    
    if (numOfZombies <= 0) {
        std::cout << "Invalid number of zombies" << std::endl;
        return 1;
    }
    
    // Create zombie horde
    Zombie* zombies = zombieHorde(numOfZombies, "Walker");
    if (!zombies) {
        std::cout << "Failed to create zombie horde" << std::endl;
        return 1;
    }
    
    // Test the zombies
    std::cout << "\nZombie horde announcing:\n" << std::endl;
    for (int i = 0; i < numOfZombies; i++) {
        zombies[i].announce();
    }
    
    // Clean up
    delete[] zombies;
    
    return 0;
}
