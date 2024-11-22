#include "Floor.hpp"
#include <iostream>

Floor::Floor() : itemCount(0) {
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		items[i] = NULL;
	}
	std::cout << "Floor Const" << std::endl;
}

Floor::~Floor() {
	cleanFloor();
	std::cout << "Floor dest" << std::endl;
}

bool Floor::addItem(AMateria* item) {
	if (isFull() || !item) {
		return false;
	}

	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (items[i] == NULL) {
			items[i] = item;
			++itemCount;
			std::cout << "Item dropped on the floor at position " << i << std::endl;
			return true;
		}
	}
	return false;
}

void Floor::removeItem(AMateria* item) {
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (items[i] == item) {
			delete items[i];
			items[i] = NULL;
			itemCount--;
			return;
		}
	}
}

void Floor::cleanFloor() {
	std::cout << "Cleaning the floor..." << std::endl;
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (items[i] != NULL) {
			delete items[i];
			items[i] = NULL;
		}
	}
	itemCount = 0;
	std::cout << "Floor cleaned!" << std::endl;
}

void Floor::displayFloor() const {
	std::cout << "Floor status:" << std::endl;
	int itemsFound = 0;
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (items[i] != NULL) {
			std::cout << "Position " << i << ": " << items[i]->getType() << std::endl;
			itemsFound++;
		}
	}
	std::cout << "Total items on floor: " << itemsFound << std::endl;
}

bool Floor::isFull() const {
	return itemCount >= MAX_FLOOR_ITEMS;
}
