#include "ScalarConverter.hpp"
#include <cmath>
#include <climits>

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
	std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	std::cout << "ScalarConverter assignment operator" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor" << std::endl;
}

void ScalarConverter::printChar(double c){
	if (std::isnan(c) || std::isinf(c) || c < CHAR_MIN || c > CHAR_MAX) throw CharImpossibleException();

	char convChar = static_cast<char>(c);

	if (std::isprint(convChar))
		std::cout << "char: \'" << convChar << "\'" << std::endl;
	else
		throw NonDisplayableException();
}

void ScalarConverter::printInt(double i){
	if (std::isnan(i) || std::isinf(i) || i < INT_MIN || i > INT_MAX) throw IntImpossibleException();

	int convInt = static_cast<int>(i);
	std::cout << "int: " << convInt << std::endl;
}

void ScalarConverter::printFloat(double f){
	float convFloat = static_cast<float>(f);
	if (convFloat - static_cast<int>(f) == 0)
		std::cout << "float: " << convFloat << ".0f" << std::endl;
	else
		std::cout << "float: " << convFloat << "f" << std::endl;
}

void ScalarConverter::printDouble(double d){
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	char *end;
	double convData;

	try {
		if (strlen(input.c_str()) == 1 && !(input[0] >= '0' && input[0] <= '9')) {
			convData = static_cast<double>(input[0]);
		}
		else {
			convData = strtod(input.c_str(), &end);
			if (input.c_str() == end && strlen(input.c_str()) != 1)
				throw InvalidInputException();
			if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0'))
				throw InvalidInputException();
		}

		try {
			printChar(convData);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			printInt(convData);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			printFloat(convData);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			printDouble(convData);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
	return "char: Non displayable";
}

const char *ScalarConverter::CharImpossibleException::what() const throw() {
	return "char: impossible";
}

const char *ScalarConverter::IntImpossibleException::what() const throw() {
	return "int: impossible";
}

const char *ScalarConverter::FloatImpossibleException::what() const throw() {
	return "float: impossible";
}

const char *ScalarConverter::DoubleImpossibleException::what() const throw() {
	return "double: impossible";
}

const char *ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input";
}
