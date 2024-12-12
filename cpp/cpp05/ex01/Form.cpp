#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToExecute(1), gradeToSign(1){
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string& name, int gradeToExecute, int gradeToSign)
			: name(name), isSigned(false), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign){
	if (gradeToExecute < 1 || gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw Form::GradeTooLowException();
	std::cout << "Form all arg constructor" << std::endl;
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeToExecute(other.gradeToExecute), gradeToSign(other.gradeToSign){
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form(){
	std::cout << "Form destructor" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() 
        << "\nGrade to Execute: " << form.getGradeToExecute() 
        << "\nGrade to Sign: " << form.getGradeToSign() 
        << "\nIs signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}

const std::string &Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) throw Form::GradeTooLowException();
	if (this->isSigned) throw Form::AlreadySignedException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high for this form";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low for this form";
}

const char* Form::AlreadySignedException::what() const throw() {
    return "Form is already signed";
}