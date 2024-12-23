#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const std::string& name);
		AForm(const std::string& name, int gradeToExecute, int gradeToSign);
		AForm(const AForm& other);
		virtual ~AForm();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToExecute() const;
		int getGradeToSign() const;
		virtual void execute(const Bureaucrat& executor) const = 0;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NotExecutedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const name;
		bool isSigned;
		int const gradeToExecute;
		int const gradeToSign;

		AForm& operator=(const AForm& other);
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
