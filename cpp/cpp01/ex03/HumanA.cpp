#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}

HumanA::~HumanA(){
	std::cout << this->name << " has been destroyed" << std::endl;
}

void HumanA::attack(){
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
