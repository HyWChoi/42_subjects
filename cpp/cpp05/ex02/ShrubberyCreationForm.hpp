#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	static const int maxGrade = 137;
	static const int minGrade = 145;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name, int gradeToExecute, int gradeToSign);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const;

		class FileOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FileWriteException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		static const std::string TREE;
};

#endif
