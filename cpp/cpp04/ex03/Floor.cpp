#include "Floor.hpp"
#include <iostream>

Floor::Floor() : itemCount(0) {
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		items[i] = NULL;
	}
	std::cout << "Floor Constructor" << std::endl;
}

Floor::~Floor() {
	cleanFloor();
	std::cout << "Floor Destructor" << std::endl;
}

bool Floor::addItem(AMateria* item) {
	if (!item) {
		std::cout << "Cannot add null item to floor" << std::endl;
		return false;
	}

	if (isFull()) {
		std::cout << "Floor is full (max " << MAX_FLOOR_ITEMS << " items)" << std::endl;
		return false;
	}

	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (!items[i]) {
			items[i] = item;
			++itemCount;
			std::cout << "Item of type '" << item->getType()
					 << "' dropped on floor at position " << i << std::endl;
			return true;
		}
	}
	return false;
}

void Floor::cleanFloor() {
	if (itemCount == 0) {
		std::cout << "Floor is already clean" << std::endl;
		return;
	}

	std::cout << "Cleaning the floor..." << std::endl;
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (items[i]) {
			delete items[i];
			items[i] = NULL;
		}
	}
	itemCount = 0;
	std::cout << "Floor cleaned!" << std::endl;
}

void Floor::displayFloor() const {
	std::cout << "\nFloor Status:" << std::endl;
	if (itemCount == 0) {
		std::cout << "Floor is empty" << std::endl;
		return;
	}

	int itemsFound = 0;
	for (int i = 0; i < MAX_FLOOR_ITEMS; ++i) {
		if (items[i]) {
			std::cout << "Position " << i << ": " << items[i]->getType() << std::endl;
			itemsFound++;
		}
	}
	std::cout << "Total items on floor: " << itemsFound << " / " << MAX_FLOOR_ITEMS << std::endl;
}

bool Floor::isFull() const {
	return itemCount >= MAX_FLOOR_ITEMS;
}
