#include "ClapTrap.hpp"

std::string ClapTrap::getName(){
	if (this->name.size() == 0)
		return "";

	return this->name;
};

ssize_t ClapTrap::getHitPoint(){
	return this->hitPoint;
};

ssize_t ClapTrap::getEnergyPoint(){
	return this->energyPoint;
};

ssize_t ClapTrap::getAttackDamage(){
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
		std::cout << "ClapTrap " << this->getName() << " is already crashed!" << std::endl;
	else if (this->getEnergyPoint() <= 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy to attack!" << std::endl;
	else
	{
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target 
            << " causing " << this->getAttackDamage() << " points of damage!" 
            << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount){
	if (this->getHitPoint() <= 0)
		std::cout << "ClapTrap " << this->getName() << " is already crashed!" << std::endl;
	else if (amount <= 0)
		std::cout << "ClapTrap " << this->getName() << " evades!" << std::endl;
	else if (this->getHitPoint() <= amount)
	{
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->getName() << " is crashed!" << std::endl;
		this->setHitPoint(-1);
	}
	else
	{
		this->setHitPoint(this->getHitPoint() - amount);
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->getName() << " remains " << this->getHitPoint() << " points of hit!" << std::endl;
	}
};

void ClapTrap::beRepaired(unsigned int amount){
	if (this->getHitPoint() <= 0)
		std::cout << "ClapTrap " << this->getName() << " is already crashed!" << std::endl;
	else if (this->getEnergyPoint() <= 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy to repair " << std::endl;
	else if (amount <= 0)
		std::cout << "ClapTrap " << this->getName() << "'s repairing is not working!" << std::endl;
	else
	{
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		this->setHitPoint(this->getHitPoint() + amount);
		std::cout << "ClapTrap " << this->getName() << " repaired itself for " << amount << " points of hit!" << std::endl;
		std::cout << "ClapTrap " << this->getName() << " has " << this->getEnergyPoint() << " points of energy!" << std::endl;
		std::cout << "ClapTrap " << this->getName() << " has " << this->getHitPoint() << " points of hit!" << std::endl;
	}
};



