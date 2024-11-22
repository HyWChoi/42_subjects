#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

HumanB::~HumanB(){
	std::cout << this->_name << " has been destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}

void HumanB::attack(){
	if (this->_weapon == NULL)
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
