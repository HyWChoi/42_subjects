#include "ScalarConverter.hpp"
#include <cmath>
#include <climits>

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor" << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	char *end;
	double convDouble = strtod(input.c_str(), &end);
	try {
		char c = static_cast<char>(convDouble);
		printChar(c);
	} catch (std::exception &e) {
		std::cout << "char: impossible" << std::endl;
	}
	try {
		if (convDouble > INT_MAX || convDouble < INT_MIN
			|| std::isnan(convDouble) || std::isinf(convDouble))
			throw std::exception();
		int i = static_cast<int>(convDouble);
		printInt(i);
	} catch (std::exception &e) {
		std::cout << "int: impossible" << std::endl;
	}
	try {
		float f = static_cast<float>(convDouble);
		printFloat(f);
	} catch (std::exception &e) {
		std::cout << "float: impossible" << std::endl;
	}
	try {
		double d = static_cast<double>(convDouble);
		printDouble(d);
	} catch (std::exception &e) {
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::printChar(char c){
	if (std::isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i){
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f){
	if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d){
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
