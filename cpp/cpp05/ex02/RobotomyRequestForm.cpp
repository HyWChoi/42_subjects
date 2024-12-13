#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 137, 145){
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, int gradeToExecute, int gradeToSign)
	: AForm(name, gradeToExecute, gradeToSign){
	std::cout << "RobotomyRequestForm all arg constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other){
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->getIsSigned()) throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::NotExecutedException();
}
