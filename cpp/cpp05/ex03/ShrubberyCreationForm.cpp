#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::TREE = "\
      ###\n\
     #####\n\
    #######\n\
   #########\n\
  ###########\n\
 ###############\n\
       H\n\
       H\n\
       H";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145){
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 137, 145){
	std::cout << "ShrubberyCreationForm all arg constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other){
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->getIsSigned()) throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::GradeTooLowException();

	std::string filename = this->getName() + "_shrubbery";
	std::ofstream file(filename);

	if (!file.is_open()) throw FileOpenException();

	file << this->TREE;
	if (file.bad()) {
		file.close();
		throw FileWriteException();
	}

	file.close();
	std::cout << "Shrubbery created in " << filename << std::endl;
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "Failed to open file";
}

const char* ShrubberyCreationForm::FileWriteException::what() const throw() {
	return "Failed to write to file";
}
