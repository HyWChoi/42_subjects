#include "Contact.hpp"

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::~Contact() {
	std::cout << "destruct Contact" << std::endl;
}

std::string	Contact::getFirstName(void){
	return this->firstName;
}

std::string	Contact::getLastName(void){
	return this->lastName;
}

std::string	Contact::getNickName(void){
	return this->nickName;

}

std::string	Contact::getPhoneNumber(void){
	return this->phoneNumber;
}

std::string	Contact::getDarkestSecret(void){
	return this->darkestSecret;
}

void	Contact::setFirstName(std::string str){
	this->firstName = str;
}

void	Contact::setLastName(std::string str){
	this->lastName = str;
}

void	Contact::setNickName(std::string str){
	this->nickName = str;
}

bool	Contact::setPhoneNumber(std::string str){
	for (int i = 0; i < (int)str.size(); i++) {
		if (str.at(i) < '0' || str.at(i) > '9') {
			return false;	
		}
	}
	this->phoneNumber = str;
	return true;
}

void	Contact::setDarkestSecret(std::string str){
	this->darkestSecret = str;
}
