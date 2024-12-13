#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 5, 25){
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, 5, 25){
	std::cout << "PresidentialPardonForm all arg constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other){
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->getIsSigned()) throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::GradeTooLowException();

	std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}