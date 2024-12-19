#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer constructor" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer destructor" << std::endl;
}

uintptr_t Serializer::serialize(const Data &data) {
	return reinterpret_cast<uintptr_t>(new Data(data));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return new Data(*reinterpret_cast<Data *>(raw));
}
