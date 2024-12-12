#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(1){
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade){
	if (grade < maxGrade) throw GradeTooHighException();
	if (grade > minGrade) throw GradeTooLowException();
	std::cout << "Bureaucrat all arg constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name) {
	*this = other;
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this == &other) return *this;
	this->grade = other.grade;
	std::cout << "Bureaucrat assignment operator" << std::endl;
	return *this;
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