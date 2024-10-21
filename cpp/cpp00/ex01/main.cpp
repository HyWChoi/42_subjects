#include "PhoneBook.hpp"

int main(){

	PhoneBook 	phoneBook;
	std::string input = "";

	while (!std::cin.eof()) {
        std::cout << "Enter a command [ADD, SEARCH, EXIT]: ";
		std::cout.flush();
        if (std::getline(std::cin, input) && !input.empty()) {
            if (input.compare("ADD") == 0)
                phoneBook.add();
            else if (input.compare("SEARCH") == 0)
                phoneBook.search();
            else if (input.compare("EXIT") == 0)
                break;
        }
        input.clear();   // Reset input string after processing
    }

	return (0);
}
