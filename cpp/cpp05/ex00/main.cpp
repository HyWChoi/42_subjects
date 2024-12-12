#include "Bureaucrat.hpp"

int main(){
	{
		std::cout << "\n=== Testing Constructors ===\n" << std::endl;
    
    	try {
        	std::cout << "Creating default bureaucrat:" << std::endl;
        	Bureaucrat b1;
        	std::cout << b1 << std::endl;

        	std::cout << "\nCreating bureaucrat with name and grade:" << std::endl;
        	Bureaucrat b2("Bob", 100);
        	std::cout << b2 << std::endl;

        	std::cout << "\nTesting copy constructor:" << std::endl;
        	Bureaucrat b3(b2);
        	std::cout << b3 << std::endl;

        	std::cout << "\nTesting assignment operator:" << std::endl;
        	Bureaucrat b4;
        	b4 = b2;
        	std::cout << b4 << std::endl;
    	}
    	catch (std::exception& e) {
    	    std::cout << "Exception: " << e.what() << std::endl;
    	}
	}
	{
		std::cout << "\n=== Testing Grade Limits ===\n" << std::endl;
    
    	try {
    	    std::cout << "Testing too high grade (0):" << std::endl;
    	    Bureaucrat b1("TooHigh", 0);
    	}
    	catch (std::exception& e) {
    	    std::cout << "Exception caught: " << e.what() << std::endl;
    	}

    	try {
    	    std::cout << "\nTesting too low grade (151):" << std::endl;
    	    Bureaucrat b2("TooLow", 151);
    	}
    	catch (std::exception& e) {
    	    std::cout << "Exception caught: " << e.what() << std::endl;
    	}
	}
	{
		std::cout << "\n=== Testing Grade Modifications ===\n" << std::endl;
    
    	try {
    	    Bureaucrat b("Test", 2);
    	    std::cout << "Initial state: " << b << std::endl;
	
    	    std::cout << "Incrementing grade" << std::endl;
    	    b.incrementGrade();
    	    std::cout << "After increment: " << b << std::endl;
	
    	    std::cout << "Trying to increment at maximum grade" << std::endl;
    	    b.incrementGrade();
    	}
    	catch (std::exception& e) {
    	    std::cout << "Exception caught: " << e.what() << std::endl;
    	}
	
    	try {
    	    Bureaucrat b("Test", 149);
    	    std::cout << "\nInitial state: " << b << std::endl;
	
    	    std::cout << "Decrementing grade" << std::endl;
    	    b.decrementGrade();
    	    std::cout << "After decrement: " << b << std::endl;
	
    	    std::cout << "Trying to decrement at minimum grade" << std::endl;
    	    b.decrementGrade();
    	}
    	catch (std::exception& e) {
    	    std::cout << "Exception caught: " << e.what() << std::endl;
    	}
	}
}