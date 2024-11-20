#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal {
	protected:
		std::string type;

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal& other);

		AAnimal& operator=(const AAnimal& other);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
