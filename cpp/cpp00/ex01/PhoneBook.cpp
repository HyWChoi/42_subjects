#include "PhoneBook.hpp"

const std::string PhoneBook::PHONEBOOKHEADER[3] = {
    "|-------------------------------------------|\n",
    "|     Index|First Name| Last Name|  Nickname|\n",
    "|----------|----------|----------|----------|"
};

const std::string PhoneBook::PHONEBOOKFOOTER[1] = {
    "|-------------------------------------------|",
};

PhoneBook::PhoneBook() {
	this->index = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << "deconstruct PhoneBook" << std::endl;
}

int	PhoneBook::getIndex() {
	return this->index;
}

void PhoneBook::setIndex(int idx) {
	this->index = idx % 8;
}

Contact PhoneBook::getContact(int idx) {
	return this->contactList[idx % 8];
}

void PhoneBook::add() {
	std::string str;
	int index = this->getIndex();

	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contactList[index].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contactList[index].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->contactList[index].setNickName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		bool isSavedPhoneNumber = false;
		std::cout << "Enter a phonenumber: ";
		if (std::getline(std::cin, str) && str != "")
		{
			isSavedPhoneNumber = this->contactList[index].setPhoneNumber(str);
			if (!isSavedPhoneNumber)
			{
				std::cout << "Wrong format" << std::endl;
				str = "";
			}
		}	
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->contactList[index].setDarkestSecret(str);
	}
	this->setIndex(++index);
}

void PhoneBook::search() {
	for (int i = 0; i < 3; ++i) {
        std::cout << this->PHONEBOOKHEADER[i] << std::endl;
    }

	for (int i = 0; i <= 7; i++) {
        std::cout << "|";
        std::cout << std::setw(10) << std::setfill(' ') << i;
        std::cout << "|";

        if (this->contactList[i].getFirstName().size() > 10)
            std::cout << std::setw(10) << std::setfill(' ') << this->contactList[i].getFirstName().substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << std::setfill(' ') << this->contactList[i].getFirstName();
        std::cout << "|";

        if (this->contactList[i].getLastName().size() > 10)
            std::cout << std::setw(10) << std::setfill(' ') << this->contactList[i].getLastName().substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << std::setfill(' ') << this->contactList[i].getLastName();
        std::cout << "|";

        if (this->contactList[i].getNickName().size() > 10)
            std::cout << std::setw(10) << std::setfill(' ') << this->contactList[i].getNickName().substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << std::setfill(' ') << this->contactList[i].getNickName();
        std::cout << "|" << std::endl;
    }
	std::cout << this->PHONEBOOKFOOTER[0] << std::endl;

	std::string userInput;
    std::cout << "Enter an index which you want to see: ";
    std::getline(std::cin, userInput);

    // Check if the input is a valid number
    bool isValid = !userInput.empty() && std::all_of(userInput.begin(), userInput.end(), ::isdigit);

    if (!isValid) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        return;
    }

    int index = std::stoi(userInput);  // Convert the valid string to integer

    if (index < 0 || index >= this->index) {
        std::cout << "Wrong index" << std::endl;
        return;
    }

    std::cout << "Index: " << index << std::endl;
    std::cout << "FirstName: " << this->contactList[index].getFirstName() << std::endl;
    std::cout << "LastName: " << this->contactList[index].getLastName() << std::endl;
    std::cout << "NickName: " << this->contactList[index].getNickName() << std::endl;
    std::cout << "PhoneNumber: " << this->contactList[index].getPhoneNumber() << std::endl;
    std::cout << "DarkestSecret: " << this->contactList[index].getDarkestSecret() << std::endl;
}