#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

class Floor {
private:
	static const int MAX_FLOOR_ITEMS = 100;
	AMateria* items[MAX_FLOOR_ITEMS];
	int itemCount;

	Floor();
	Floor(const Floor& other);
	Floor& operator=(const Floor& other);

public:
	~Floor();

	static Floor& getInstance() {
		static Floor instance;
		return instance;
	}

	bool addItem(AMateria* item);
	void cleanFloor();
	void displayFloor() const;
	bool isFull() const;
};
#endif
