#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// void leaks() {
// 	system("leaks Intern");
// }

int main() {

	// atexit(leaks);

    std::cout << "=== Testing Intern AForm Creation ===" << std::endl;
    std::cout << std::endl;

    try {
        Intern someRandomIntern;
        AForm* Aform = NULL;

        std::cout << "--- Testing RobotomyRequestForm ---" << std::endl;
        Aform = someRandomIntern.makeForm("robotomy request", "Bender");
        if (Aform) {
            std::cout << *Aform << std::endl;
            delete Aform;
        }
        std::cout << std::endl;

        std::cout << "--- Testing PresidentialPardonForm ---" << std::endl;
        Aform = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        if (Aform) {
            std::cout << *Aform << std::endl;
            delete Aform;
        }
        std::cout << std::endl;

        std::cout << "--- Testing ShrubberyCreationForm ---" << std::endl;
        Aform = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (Aform) {
            std::cout << *Aform << std::endl;
            delete Aform;
        }
        std::cout << std::endl;

        std::cout << "--- Testing Invalid AForm Name ---" << std::endl;
        Aform = someRandomIntern.makeForm("invalid Aform", "Target");
        if (Aform) {
            delete Aform;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with Bureaucrat ===" << std::endl;
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat newbie("Newbie", 150);

        AForm* robotomyForm = intern.makeForm("robotomy request", "R2D2");
        if (robotomyForm) {
            std::cout << "\nTrying to sign and execute with newbie:" << std::endl;
            newbie.signForm(*robotomyForm);
            newbie.executeForm(*robotomyForm);

            std::cout << "\nTrying to sign and execute with boss:" << std::endl;
            boss.signForm(*robotomyForm);
            boss.executeForm(*robotomyForm);

            delete robotomyForm;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

	try {
		Intern intern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat newbie("Newbie", 150);

		AForm* presidentialForm = intern.makeForm("presidential pardon", "Criminal");
		if (presidentialForm) {
			std::cout << "\nTrying to sign and execute with newbie:" << std::endl;
			newbie.signForm(*presidentialForm);
			newbie.executeForm(*presidentialForm);

			std::cout << "\nTrying to sign and execute with boss:" << std::endl;
			boss.signForm(*presidentialForm);
			boss.executeForm(*presidentialForm);

			delete presidentialForm;
		}
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		Bureaucrat newbie("Newbie", 150);

		AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
		if (shrubberyForm) {
			std::cout << "\nTrying to sign and execute with newbie:" << std::endl;
			newbie.signForm(*shrubberyForm);
			newbie.executeForm(*shrubberyForm);

			std::cout << "\nTrying to sign and execute with boss:" << std::endl;
			boss.signForm(*shrubberyForm);
			boss.executeForm(*shrubberyForm);

			delete shrubberyForm;
		}
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

    return 0;
}