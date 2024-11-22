#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){}

HumanB::~HumanB(){
	std::cout << this->name << " has been destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}

void HumanB::attack(){
	if (this->weapon == NULL)
		std::cout << this->name << " has no weapon to attack with" << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
