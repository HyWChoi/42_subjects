#include "Animal.hpp"

AAnimal::AAnimal(){
	this->type = "AAnimal";
	std::cout << "AAnimal Constructor" << std::endl;
};

AAnimal::~AAnimal(){
	std::cout << "AAnimal Destructor" << std::endl;
};

AAnimal::AAnimal(const AAnimal& other){
	*this = other;
	std::cout << "AAnimal copy constructor called" << std::endl;
};

AAnimal& AAnimal::operator=(const AAnimal& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "AAnimal assighment operator called" << std::endl;
	}
	return *this;
};

std::string AAnimal::getType() const {
	return this->type;
};
