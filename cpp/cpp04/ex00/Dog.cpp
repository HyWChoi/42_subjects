#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog Constructor" << std::endl;
};

Dog::~Dog(){
	std::cout << "Dog Destructor" << std::endl;
};

Dog::Dog(const Dog& other) : Animal(other){
	std::cout << "Dog copy constructor called" << std::endl;
};

Dog& Dog::operator=(const Dog& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "Dog assighment operator called" << std::endl;
	}
	return *this;
};

void Dog::makeSound() const{
	std::cout << "Dog barks" << std::endl;
};
