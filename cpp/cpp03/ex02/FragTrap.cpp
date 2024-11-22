#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->type = "FragTrap";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "no arg FragTrap constructor called" << std::endl;
};

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->type = "FragTrap";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap assignment operator called" << std::endl;
	return *this;
};

void FragTrap::highFivesGuys(void) {
	std::cout << this->getType() << this->getName() << " requests a positive high five! ✋" << std::endl;
}
