#include "Serializer.hpp"
#include <iostream>

int main() {
	Data originalData;
	originalData.s1 = "Hello, Serialization!";
	originalData.n = 42;

	std::cout << "\n=== Original Data ===" << std::endl;
	std::cout << "String (s1): " << originalData.s1 << std::endl;
	std::cout << "Number (n): " << originalData.n << std::endl;
	std::cout << "Address: " << &originalData << std::endl;
	std::cout << std::endl;

	// Serialize
	uintptr_t serialized = Serializer::serialize(originalData);
	std::cout << "=== Serialization ===" << std::endl;
	std::cout << "Serialized: " << serialized << std::endl;
	std::cout << std::endl;

	// Deserialize
	Data* deserialized = Serializer::deserialize(serialized);

	// Print deserialized data
	std::cout << "=== Deserialized Data ===" << std::endl;
	std::cout << "String (s1): " << deserialized->s1 << std::endl;
	std::cout << "Number (n): " << deserialized->n << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << std::endl;

	// Verify data
	std::cout << "=== Data Verification ===" << std::endl;
	bool stringMatch = (originalData.s1 == deserialized->s1);
	bool numberMatch = (originalData.n == deserialized->n);

	std::cout << "String match: " << (stringMatch ? "YES" : "NO") << std::endl;
	std::cout << "Number match: " << (numberMatch ? "YES" : "NO") << std::endl;
	std::cout << std::endl;

	delete deserialized;

	return 0;
}
