#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

	static const int maxGrade = 1;
	static const int minGrade = 150;


	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		int getGrade() const;
		const std::string &getName() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const name;
		int grade;

		Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
