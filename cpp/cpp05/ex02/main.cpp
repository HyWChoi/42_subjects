#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "\n=== Testing Grade Increments/Decrements ===\n" << std::endl;
	try {
		Bureaucrat b("Test", 2);
		std::cout << b << std::endl;

		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;

		b.incrementGrade(); // Should throw exception
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Test", 149);
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;

		b.decrementGrade(); // Should throw exception
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Invalid Grades ===\n" << std::endl;
	try {
		Bureaucrat tooHigh("Too High", 0);	// Should throw exception
	} catch (std::exception& e) {
		std::cout << "Creating bureaucrat with grade 0: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooLow("Too Low", 151);	// Should throw exception
	} catch (std::exception& e) {
		std::cout << "Creating bureaucrat with grade 151: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing ShrubberyCreationForm ===\n" << std::endl;
	try {
		Bureaucrat high("High Level", 1);
		Bureaucrat mid("Mid Level", 140);
		Bureaucrat low("Low Level", 150);

		ShrubberyCreationForm form("garden");

		// Test signing with different bureaucrats
		std::cout << "Testing signing..." << std::endl;
		low.signForm(form); // Should fail
		mid.signForm(form); // Should succeed

		// Test execution with different bureaucrats
		std::cout << "\nTesting execution..." << std::endl;
		low.executeForm(form);  // Should fail (grade too low)
		high.executeForm(form); // Should succeed

	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing RobotomyRequestForm ===\n" << std::endl;
	try {
		Bureaucrat high("High Level", 1);
		Bureaucrat mid("Mid Level", 70);
		Bureaucrat low("Low Level", 150);

		RobotomyRequestForm form("RobotomyRequestForm");

		// Test signing
		std::cout << "Testing signing..." << std::endl;
		low.signForm(form); // Should fail
		mid.signForm(form); // Should succeed

		// Test multiple executions to see success/failure rate
		std::cout << "\nTesting multiple executions..." << std::endl;
		for (int i = 0; i < 5; i++) {
			high.executeForm(form);
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing PresidentialPardonForm ===\n" << std::endl;
	try {
		Bureaucrat president("President", 1);
		Bureaucrat minister("Minister", 20);
		Bureaucrat intern("Intern", 150);

		PresidentialPardonForm form("Criminal");

		// Test signing
		std::cout << "Testing signing..." << std::endl;
		intern.signForm(form);	  // Should fail
		minister.signForm(form);	// Should succeed

		// Test execution
		std::cout << "\nTesting execution..." << std::endl;
		minister.executeForm(form); // Should fail (grade too low)
		president.executeForm(form); // Should succeed=
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
