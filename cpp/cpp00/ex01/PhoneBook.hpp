#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		int _nbContacts;
		void setNbContacts(int nbContacts);
		void setContact(Contact contact, int index);
	public:
		int getNbContacts();
		void addContact();
		void searchContact();
		void printContact();
		PhoneBook();
		~PhoneBook();
};

#endif
