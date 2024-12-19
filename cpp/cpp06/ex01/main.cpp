#include "Serializer.hpp"
#include <iostream>

int main() {
	Serializer s;
	Data data = {"Hello", 42};
	uintptr_t raw = s.serialize(data);
	Data *data2 = s.deserialize(raw);
	std::cout << data2->s1 << " " << data2->n << std::endl;
	delete data2;
	return 0;
}
