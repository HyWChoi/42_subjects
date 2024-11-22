#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
};

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed::Fixed(const int n) : value(n << bits){
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float n) : value(roundf(n * (1 << bits))){
    std::cout << "Float constructor called" << std::endl;
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

bool Fixed::operator>(const Fixed& other) const { return this->value > other.value; };
bool Fixed::operator<(const Fixed& other) const { return this->value < other.value; };
bool Fixed::operator>=(const Fixed& other) const { return this->value >= other.value; };
bool Fixed::operator<=(const Fixed& other) const { return this->value <= other.value; };
bool Fixed::operator==(const Fixed& other) const { return this->value == other.value; };
bool Fixed::operator!=(const Fixed& other) const { return this->value != other.value; };

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
};

void Fixed::setRawBits(int const raw) {
    this->value = raw;
};

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.value = (this->value * other.value) >> this->bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.value = (this->value << this->bits) / other.value;
    return result;
}

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

const Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

const Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

float Fixed::toFloat(void) const {
    return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const {
    return this->value >> bits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// 출력 스트림 연산자 구현 추가
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}