#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	static const int maxGrade = 72;
	static const int minGrade = 45;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name, int gradeToExecute, int gradeToSign);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void execute(const Bureaucrat& executor) const;

	private:
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

#endif
