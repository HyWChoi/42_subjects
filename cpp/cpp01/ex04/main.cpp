#include <iostream>
#include <fstream>

void	replace(std::string filename, std::string s1, std::string s2){
	std::ifstream inFILE(filename);

	if (!inFILE){
		std::cout << "Error: Could not open file: " << filename << std::endl;
		return ;
	}
	std::string outFILENAME = filename + ".replace";
	std::ofstream outFILE(outFILENAME);
}

int	main(int argc, char* argv[]){
	if (argc != 4){
		std::cout << "TOO LESS ARGUMENTS" << std::endl;
		return (0);
	}

	return (0);
}
