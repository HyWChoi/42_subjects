#include "FragTrap.hpp"
#include <iostream>

int main() {
    // Test default constructor
    FragTrap defaultFrag;
    std::cout << "\n";

    // Test named constructor
    FragTrap frag("FR4G-TP");
    std::cout << "\n";

    // Test copy constructor
    FragTrap copyFrag(frag);
    std::cout << "\n";

    // Test assignment operator
    FragTrap assignFrag;
    assignFrag = frag;
    std::cout << "\n";

    // Test functionality
    frag.attack("Enemy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    std::cout << "\n";

    // Objects will be destroyed in reverse order
    return 0;
}
