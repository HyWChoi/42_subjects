#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name(""), hitPoint(10), energyPoint(10), attackDamage(0), type("ClapTrap") {
	std::cout << "no arg ClapTrap constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name):name(name), hitPoint(10), energyPoint(10), attackDamage(0), type("ClapTrap") {
	std::cout << "ClapTrap constructor called" << std::endl;
};

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap deconstructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other){
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other) {
		this->name = other.name;
		this->hitPoint = other.hitPoint;
		this->energyPoint = other.energyPoint;
		this->attackDamage = other.attackDamage;
		std::cout << "ClapTrap assignment operator called" << std::endl;
	}
	return *this;
};

std::string ClapTrap::getName() const{
	if (this->name.size() == 0)
		return "";

	return this->name;
};

std::string ClapTrap::getType() const{
	if (this->name.size() == 0)
		return "";

	return this->name;
};

ssize_t ClapTrap::getHitPoint() const{
	return this->hitPoint;
};

ssize_t ClapTrap::getEnergyPoint() const{
	return this->energyPoint;
};

ssize_t ClapTrap::getAttackDamage() const{
	return this->attackDamage;
};

void ClapTrap::setName(const std::string &name){
	this->name = name;
};

void ClapTrap::setHitPoint(int hitPoint){
	this->hitPoint = hitPoint;
};

void ClapTrap::setEnergyPoint(int energyPoint){
	this->energyPoint = energyPoint;
};

void ClapTrap::setAttackDamage(int attackDamage){
	this->attackDamage = attackDamage;
};


void ClapTrap::attack(const std::string& target){
	if (this->getHitPoint() <= 0)
		std::cout << this->getType() << this->getName() << " is already crashed!" << std::endl;
	else if (this->getEnergyPoint() <= 0)
		std::cout << this->getType() << this->getName() << " has no energy to attack!" << std::endl;
	else
	{
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		std::cout << this->getType() << this->getName() << " attacks " << target
			<< " causing " << this->getAttackDamage() << " points of damage!"
			<< std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount){
	if (this->getHitPoint() <= 0)
		std::cout << this->getType() << this->getName() << " is already crashed!" << std::endl;
	else if (amount <= 0)
		std::cout << this->getType() << this->getName() << " evades!" << std::endl;
	else if (this->getHitPoint() <= amount)
	{
		std::cout << this->getType() << this->getName() << " takes " << amount << " points of damage!" << std::endl;
		std::cout << this->getType() << this->getName() << " is crashed!" << std::endl;
		this->setHitPoint(-1);
	}
	else
	{
		this->setHitPoint(this->getHitPoint() - amount);
		std::cout << this->getType() << this->getName() << " takes " << amount << " points of damage!" << std::endl;
		std::cout << this->getType() << this->getName() << " remains " << this->getHitPoint() << " points of hit!" << std::endl;
	}
};

void ClapTrap::beRepaired(unsigned int amount){
	if (this->getHitPoint() <= 0)
		std::cout << this->getType() << this->getName() << " is already crashed!" << std::endl;
	else if (this->getEnergyPoint() <= 0)
		std::cout << this->getType() << this->getName() << " has no energy to repair " << std::endl;
	else if (amount <= 0)
		std::cout << this->getType() << this->getName() << "'s repairing is not working!" << std::endl;
	else
	{
		if (amount > 0 && this->getHitPoint() > INT_MAX - amount) {
			std::cout << this->getType() << this->getName() << "'s repair would exceed maximum hit points!" << std::endl;
			return ;
		}
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		this->setHitPoint(this->getHitPoint() + amount);
		std::cout << this->getType() << this->getName() << " repaired itself for " << amount << " points of hit!" << std::endl;
		std::cout << this->getType() << this->getName() << " has " << this->getEnergyPoint() << " points of energy!" << std::endl;
		std::cout << this->getType() << this->getName() << " has " << this->getHitPoint() << " points of hit!" << std::endl;
	}
};
