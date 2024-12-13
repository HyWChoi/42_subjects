#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToExecute(1), gradeToSign(1){
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string& target) : name(target), isSigned(false), gradeToExecute(1), gradeToSign(1){
    std::cout << "AForm name constructor" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToExecute, int gradeToSign)
			: name(name), isSigned(false), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign){
	if (gradeToExecute < 1 || gradeToSign < 1)
        throw AForm::GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw AForm::GradeTooLowException();
	std::cout << "AForm all arg constructor" << std::endl;
}

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeToExecute(other.gradeToExecute), gradeToSign(other.gradeToSign){
	std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform) {
    out << "AForm: " << Aform.getName()
        << "\nGrade to Execute: " << Aform.getGradeToExecute()
        << "\nGrade to Sign: " << Aform.getGradeToSign()
        << "\nIs signed: " << (Aform.getIsSigned() ? "Yes" : "No");
    return out;
}

const std::string &AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) throw AForm::GradeTooLowException();
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high for this Aform";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low for this Aform";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm is not signed";
}

const char* AForm::NotExecutedException::what() const throw() {
    return "AForm is not executed";
}
