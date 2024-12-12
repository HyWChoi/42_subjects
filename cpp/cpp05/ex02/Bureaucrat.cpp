#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(1){
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade){
	if (grade < maxGrade) throw GradeTooHighException();
	if (grade > minGrade) throw GradeTooLowException();
	std::cout << "Bureaucrat all arg constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor" << std::endl;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

const std::string &Bureaucrat::getName() const{
	return this->name;
}

void Bureaucrat::incrementGrade(){
	if (this->grade == maxGrade) throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(){
	if (this->grade == minGrade) throw GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}