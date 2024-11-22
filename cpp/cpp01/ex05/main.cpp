#include "Harl.hpp"

int	main(){
	Harl harl;

	std::cout << "Testing all Harl's complaint levels:\n\n";

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}
