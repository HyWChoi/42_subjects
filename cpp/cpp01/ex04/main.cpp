#include "Sed.hpp"

int	main(int argc, char* argv[]){
	if (argc != 4){
		std::cout << "TOO LESS ARGUMENTS" << std::endl;
		return 0;
	}

	Sed sed = Sed(argv[1], argv[2], argv[3]);
	try {
		sed.sed();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
