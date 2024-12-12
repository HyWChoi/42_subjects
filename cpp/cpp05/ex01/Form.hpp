#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string& name, int gradeToExecute, int gradeToSign);
		Form(const Form& other);
		~Form();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToExecute() const;
		int getGradeToSign() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const name;
		bool isSigned;
		int const gradeToExecute;
		int const gradeToSign;

		Form& operator=(const Form& other);
};

std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif