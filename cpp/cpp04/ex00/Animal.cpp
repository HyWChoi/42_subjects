#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
	std::cout << "Animal Constructor" << std::endl;
};

Animal::~Animal(){
	std::cout << "Animal Destructor" << std::endl;
};

Animal::Animal(const Animal& other){
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
};

Animal& Animal::operator=(const Animal& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "Animal assighment operator called" << std::endl;
	}
	return *this;
};

std::string Animal::getType() const {
	return this->type;
};

void Animal::makeSound() const {
	std::cout << "Animal barks" << std::endl;
};
