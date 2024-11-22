#include "Zombie.hpp"

Zombie::Zombie(): name("default"){}

Zombie::~Zombie(){
	std::cout << this->getName() << " is dead" << std::endl;
}

std::string Zombie::getName(){
	return this->name;
}

void Zombie::setName(std::string name){
	this->name = name;
}

void Zombie::announce(){
	std::cout << this->getName() << ": \"" <<  " Braiiiiiiinnnssss...\"" << std::endl;
}
