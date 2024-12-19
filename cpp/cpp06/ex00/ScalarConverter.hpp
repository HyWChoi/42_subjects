#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter {
	public:
		ScalarConverter();
		~ScalarConverter();

		void convert(const std::string &input);
	private:
		void printChar(char c);
		void printInt(int i);
		void printFloat(float f);
		void printDouble(double d);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
};

#endif
