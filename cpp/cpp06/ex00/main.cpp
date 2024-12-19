#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	ScalarConverter sc;

	if (argc != 2) {
		std::cout << "Usage: ./convert <value>" << std::endl;
		return 1;
	}

	sc.convert(argv[1]);
	return 0;
}
