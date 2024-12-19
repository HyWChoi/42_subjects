#include "iter.hpp"

int main(){

	std::cout << "int tab[] = {0, 1, 2, 3, 4};" << std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	::iter(tab, 5, print);
	std::cout << "___________________________" << std::endl;

	std::cout << "char tab2[] = {'a', 'b', 'c', 'd', 'e'};" << std::endl;
	char tab2[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(tab2, 5, print);
	std::cout << "___________________________" << std::endl;

	std::cout << "std::string tab3[] = {\"one\", \"two\", \"three\", \"four\", \"five\"};" << std::endl;
	std::string tab3[] = {"one", "two", "three", "four", "five"};
	::iter(tab3, 5, print);
	std::cout << "___________________________" << std::endl;

	std::cout << "float tab4[] = {0.1, 0.2, 0.3, 0.4, 0.5};" << std::endl;
	double tab4[] = {0.1, 0.2, 0.3, 0.4, 0.5};
	::iter(tab4, 5, print);
	std::cout << "___________________________" << std::endl;

	std::cout << "float tab5[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};" << std::endl;
	float tab5[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
	::iter(tab5, 5, print);
	std::cout << "___________________________" << std::endl;
}
