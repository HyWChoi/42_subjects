#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat Constructor" << std::endl;
};

Cat::~Cat(){
	std::cout << "Cat Destructor" << std::endl;
};

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
};

Cat& Cat::operator=(const Cat& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "Cat assighment operator called" << std::endl;
	}
	return *this;
};

void Cat::makeSound() const {
	std::cout << "Cat barks" << std::endl;
};
