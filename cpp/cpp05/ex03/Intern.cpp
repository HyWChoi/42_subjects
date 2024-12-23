#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(Intern const & src) {
	std::cout << "Intern copy constructor" << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const & src) {
	std::cout << "Intern assignment operator" << std::endl;
	if (this != &src) {
		(void)src;
	}
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

AForm *Intern::makeForm(std::string name, std::string target){
	std::cout << "Intern makeForm" << std::endl;
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw Intern::FormNotFoundException();
}