#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "Contact.hpp"

class PhoneBook {

	private:
	    static const std::string PHONEBOOKHEADER[3];
	    static const std::string PHONEBOOKFOOTER[1];
		Contact contactList[8];
		int		index;

	public:
		PhoneBook();
		~PhoneBook();
		int		getIndex();
		void	setIndex(int idx);
		Contact getContact(int idx);
		void	add();
		void	search();
};

#endif
