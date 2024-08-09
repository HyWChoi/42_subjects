#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type){
}

Weapon::Weapon(){
	this->_type = "default";
}

Weapon::~Weapon(){
	std::cout << "Weapon has been destroyed" << std::endl;
}

void Weapon::setType(std::string type){
	this->_type = type;
}

std::string Weapon::getType(){
	return this->_type;
}
