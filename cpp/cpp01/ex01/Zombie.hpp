#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		std::string getName();
		void announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif
