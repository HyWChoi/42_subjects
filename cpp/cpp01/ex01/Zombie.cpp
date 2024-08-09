#include "Zombie.hpp"

Zombie::Zombie(): _name("default"){}

Zombie::~Zombie(){
	std::cout << this->getName() << " is dead" << std::endl;
}

std::string Zombie::getName(){
	return this->_name;
}

void Zombie::setName(std::string name){
	this->_name = name;
}

void Zombie::announce(){
	std::cout << this->getName() << ": \"" <<  " Braiiiiiiinnnssss...\"" << std::endl;
}
