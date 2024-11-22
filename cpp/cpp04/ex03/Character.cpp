#include "Character.hpp"

Character::Character() :
	name(""),
	presentEquipIndex(0) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const & characterName) :
	name(characterName),
	presentEquipIndex(0) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
	}
}

Character::Character(const Character& other) :
	name(other.name),
	presentEquipIndex(other.presentEquipIndex) {

	for (int i = 0; i < 4; i++) {
		if(inventory[i])
			delete inventory[i];
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		presentEquipIndex = other.presentEquipIndex;

		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				delete inventory[i];
		}

		for (int i = 0; i < 4; i++) {
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const{
	return this->name;
};

int Character::getPresentEquipIndex() const{
	return this->presentEquipIndex;
};

void Character::setPresentEquipIndex(int index){
	this->presentEquipIndex = index % 4;
};

void Character::equip(AMateria* m) {
	if (presentEquipIndex >= 4) {
		std::cout << "inventory is full" << std::endl;
		delete m;
		return;
	}
	else if (m == NULL) {
		std::cout << "cant find inventory" << std::endl;
		delete m;
		return;
	}

	this->inventory[this->presentEquipIndex] = m;
	std::cout << "equit in " << this->presentEquipIndex << "'th inventory" << std::endl;
	this->presentEquipIndex++;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL){
		std::cout << "cant find inventory" << std::endl;
		return;
	}

	if (!Floor::getInstance().addItem(inventory[idx])) {
		std::cout << "Floor is full! Cannot drop more items!" << std::endl;
		return;
	}

	inventory[idx] = nullptr;
	std::cout << name << " unequipped item at position " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL){
		std::cout << "cant find inventory" << std::endl;
		return;
	}
	inventory[idx]->use(target);
}
