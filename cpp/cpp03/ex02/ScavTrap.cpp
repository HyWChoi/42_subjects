#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), isGuardingGate(false) {
	this->type = "ScavTrap";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "no arg ScavTrap constructor called" << std::endl;
};

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), isGuardingGate(false) {
	this->type = "ScavTrap";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	this->isGuardingGate = other.isGuardingGate;
	std::cout << "ScavTrap copy constructor called" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->isGuardingGate = other.isGuardingGate;
	}
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return *this;
};

void ScavTrap::attack(const std::string& target){
	if (this->getHitPoint() <= 0)
		std::cout << this->getType() << this->getName() << " is already crashed!" << std::endl;
	else if (this->getEnergyPoint() <= 0)
		std::cout << this->getType() << this->getName() << " has no energy to attack!" << std::endl;
	else if (!this->isGuardingGate)
		std::cout << this->getType() << this->getName() << " isn't guarding gate now" << std::endl;
	else
	{
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		std::cout << this->getType() << this->getName() << " attacks " << target
			<< " causing " << this->getAttackDamage() << " points of damage!"
			<< std::endl;
	}
};

void ScavTrap::guardGate(){
	if (!this->isGuardingGate)
		std::cout << this->getType() << this->getName() << " isn't guarding gate now" << std::endl;
	else
		std::cout << this->getType() << this->getName() << " is guarding gate now" << std::endl;
};

