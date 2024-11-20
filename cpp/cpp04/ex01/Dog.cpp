#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Constructor" << std::endl;
};

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog Destructor" << std::endl;
};

Dog::Dog(const Dog& other) : Animal(other){
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
};

Dog& Dog::operator=(const Dog& other){
	if (this != &other) {
		this->type = other.type;
		delete brain;
		this->brain = new Brain(*other.brain);
		std::cout << "Dog assighment operator called" << std::endl;
	}
	return *this;
};

void Dog::makeSound() const{
	std::cout << "Dog barks" << std::endl;
};

Brain* Dog::getBrain() const {
	return brain;
}
