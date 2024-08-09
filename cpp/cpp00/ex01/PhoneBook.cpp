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

void	PhoneBook::addContact(){
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	if (getNbContacts() == 8)
	{
		std::cout << "PhoneBook is full" << std::endl;
		return ;
	}
	std::cout << "Enter first name: ";
	std::cin >> firstName;
	contact.setFirstName(firstName);
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	contact.setLastName(lastName);
	std::cout << "Enter nickname: ";
	std::cin >> nickName;
	contact.setNickName(nickName);
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	contact.setPhoneNumber(nickName);
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	contact.setDarkestSecret(darkestSecret);
	setContact(contact, _nbContacts);
	setNbContacts(getNbContacts() + 1);
	return ;
}

void PhoneBook::searchContact(){
	std::string index;
	int i;

	if (getNbContacts() == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < getNbContacts(); i++)
	{
		std::cout << "         " << i << "|";
		std::cout << _contacts[i].getFirstName() << "|";
		std::cout << _contacts[i].getLastName() << "|";
		std::cout << _contacts[i].getNickName() << std::endl;
	}
	std::cout << "Enter index: ";
	std::cin >> index;
	if (index.length() != 1 || index[0] < '0' || index[0] > '7')
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	i = index[0] - '0';
	if (i >= getNbContacts())
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[i].getNickName() << std::endl;
	std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
	return ;
}

void PhoneBook::printContact(){
	std::string command;

	while (1)
	{
		std::cout << "Enter command: ";
		std::cin >> command;
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
