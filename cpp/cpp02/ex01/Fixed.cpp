#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
};

Fixed::Fixed(const int n) : value(n << bits){
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float n) : value(roundf(n * (1 << bits))){
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
};

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
};

void Fixed::setRawBits(int const raw) {
	this->value = raw;
};

float Fixed::toFloat(void) const {
	return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const {
	return this->value >> bits;
}
