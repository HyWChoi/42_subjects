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
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);

		std::string getName() const;
		ssize_t getHitPoint() const;
		ssize_t getEnergyPoint() const;
		ssize_t getAttackDamage() const;

		void setName(const std::string &name);
		void setHitPoint(int hitPoint);
		void setEnergyPoint(int energyPoint);
		void setAttackDamage(int attackDamage);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
