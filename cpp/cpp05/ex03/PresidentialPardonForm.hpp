#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	static const int maxGrade = 25;
	static const int minGrade = 5;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void execute(const Bureaucrat& executor) const;

	private:
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

#endif
