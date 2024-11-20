#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "WrongCat Constructor" << std::endl;
};

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor" << std::endl;
};

WrongCat::WrongCat(const WrongCat& other){
	*this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "WrongCat assighment operator called" << std::endl;
	}
	return *this;
};

void WrongCat::makeSound() const {
	std::cout << "WrongCat barks" << std::endl;
};
