#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Floor.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* inventory[4];
		int presentEquipIndex;

	public:
		Character();
		Character(std::string const & name);
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);

		std::string const & getName() const;
		int getPresentEquipIndex() const;
		void setPresentEquipIndex(int index);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif
