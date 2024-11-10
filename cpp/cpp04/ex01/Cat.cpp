#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Constructor" << std::endl;
};

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat Destructor" << std::endl;
};

Cat::Cat(const Cat& other) : Animal(other){
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
};

Cat& Cat::operator=(const Cat& other){
	if (this != &other) {
		this->type = other.type;
		delete brain;
		this->brain = new Brain(*other.brain);
		std::cout << "Cat assighment operator called" << std::endl;
	}
	return *this;
};

void Cat::makeSound() const {
	std::cout << "Cat barks" << std::endl;
};

Brain* Cat::getBrain() const {
	return brain;
}
