#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct Data {
	std::string s1;
	int n;
} Data;

class Serializer {
	public:
		Serializer();
		~Serializer();

		static uintptr_t serialize(const Data &data);
		static Data *deserialize(uintptr_t raw);

	private:
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
};

#endif
