#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72){
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, 45, 72){
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
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::GradeTooLowException();

	srand(time(NULL));
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2) std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else std::cout << this->getName() << " robotomization failed" << std::endl;
}
