#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "Error: Number of zombies must be positive" << std::endl;
        return NULL;  // Using NULL instead of nullptr
    }
    
    Zombie* zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        // Using stringstream instead of std::to_string
        std::stringstream ss;
        ss << name << "_" << (i + 1);
        zombies[i].setName(ss.str());
    }
    return zombies;
}