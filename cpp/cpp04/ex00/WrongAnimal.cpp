#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Constructor" << std::endl;
};

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	*this = other;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "WrongAnimal assighment operator called" << std::endl;
	}
	return *this;
};

std::string WrongAnimal::getType() const {
	return this->type;
};

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal barks" << std::endl;
};
