#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _nbContacts(0){
	std::cout << "PhoneBook is created" << std::endl;
}

PhoneBook::~PhoneBook(){
	std::cout << "PhoneBook is destroyed" << std::endl;
}

int	PhoneBook::getNbContacts(){
	return _nbContacts;
}

void PhoneBook::setNbContacts(int nbContacts){
	_nbContacts = nbContacts;
}

void PhoneBook::setContact(Contact contact, int index){
	_contacts[index] = contact;
}

bool	PhoneBook::isNonePrintable(std::string str){
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < 32 || str[i] > 126)
			return true;
	}
	return false;
}

bool	PhoneBook::isOnlyWhitespace(std::string str){
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
			return false;
	}
	return true;
}

void	PhoneBook::safetyCin(std::string &str, std::string target){
	str = "";

	while (1){
		std::getline(std::cin, str);
		if (std::cin.eof())
		{

		}
		std::cout << "Enter " << target << ": ";
		if (str == "")
			std::cout << "Invalid " << target << std::endl;
	}
}

void	PhoneBook::addContact(){
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	if (getNbContacts() == 8)
	{
		if (getNbContacts() == 8)
			setNbContacts(0);
		return ;
	}
	this->safetyCin(firstName, "first name");
	if (firstName == "")
		return ;
	contact.setFirstName(firstName);
	this->safetyCin(lastName, "last name");
	contact.setLastName(lastName);
	this->safetyCin(nickName, "nickname");
	contact.setNickName(nickName);
	this->safetyCin(phoneNumber, "phone number");
	contact.setPhoneNumber(phoneNumber);
	this->safetyCin(darkestSecret, "darkest secret");
	contact.setDarkestSecret(darkestSecret);
	setContact(contact, _nbContacts);
	setNbContacts(getNbContacts() + 1);
	return ;
}

void PhoneBook::printUnder10(std::string str){
	if (str.length() > 10)
		std::cout << str.substr(0,9) << "." << std::endl;
	else {
		int i = 10 - str.length();
		for (int j = 0; j < i; j++){
			std::cout << " ";
		}
		std::cout << str << "|";
	}
}

void PhoneBook::searchContact(){
	std::string index;
	int i;

	if (this->getNbContacts() == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < this->getNbContacts(); i++)
	{
		std::cout << "         " << i << "|";
		printUnder10(this->_contacts[i].getLastName());
		printUnder10(this->_contacts[i].getFirstName());
		printUnder10(this->_contacts[i].getNickName());
		std::cout << std::endl;
	}
	std::cout << "Enter index: ";
	std::cin >> index;
	if (index.length() != 1 || index[0] < '0' || index[0] > '7')
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	i = index[0] - '0';
	if (i >= this->getNbContacts())
	{
		std::cout << "Invalid index" << std::endl;
		std::cout << "num of Stored Contacts is " << this->getNbContacts() << std::endl;
		return ;
	}
	std::cout << "First name: " << this->_contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[i].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[i].getDarkestSecret() << std::endl;
	return ;
}

void PhoneBook::printContact(){
	std::string command;

	while (1)
	{
		getline(std::cin, command);
		if (std::cin.eof())
			continue ;
		if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
		else if (command == "EXIT")
			return ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return ;
}
