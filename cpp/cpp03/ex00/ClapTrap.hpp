#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string name;
		ssize_t hitPoint;
		ssize_t energyPoint;
		ssize_t attackDamage;
	public:
		ClapTrap():name(""), hitPoint(10), energyPoint(10), attackDamage(0) {
			std::cout << "no arg ClapTrap constructor called" << std::endl;
		};
		ClapTrap(std::string name):name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
			std::cout << "ClapTrap constructor called" << std::endl;
		};
		~ClapTrap(){
			std::cout << "ClapTrap deconstructor called" << std::endl;
		};
		ClapTrap(const ClapTrap& other){
			*this = other;
		};
		ClapTrap& operator=(const ClapTrap& other){
			if (this != &other) {
                this->name = other.name;
                this->hitPoint = other.hitPoint;
                this->energyPoint = other.energyPoint;
                this->attackDamage = other.attackDamage;
            }
            return *this;
		};

		std::string getName();
		ssize_t getHitPoint();
		ssize_t getEnergyPoint();
		ssize_t getAttackDamage();

		void setName(const std::string &name);
		void setHitPoint(int hitPoint);
		void setEnergyPoint(int energyPoint);
		void setAttackDamage(int attackDamage);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

#endif