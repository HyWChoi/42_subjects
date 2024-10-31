#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	private:
		void setType();

	protected:
		std::string type;

	public:
		// std::string getType();
		// virtual void makeSound() = 0;
};

#endif