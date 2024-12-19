#include "Array.hpp"

int main(){
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i;

		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << std::endl;

		try {
			std::cout << a[6] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::ostringstream ss;
		std::string test = "test ";
		Array<std::string> a(5);

		for (unsigned int i = 0; i < a.size(); i++){
			ss << test << i;
			a[i] = ss.str();
			ss.str("");
		}

		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << std::endl;

		try {
			std::cout << a[6] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
