#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <climits>
# include <cfloat>

class ScalarConverter {
	public:
		static void convert(const std::string &input);
		ScalarConverter();
		~ScalarConverter();

		class NonDisplayableException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class CharImpossibleException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class IntImpossibleException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FloatImpossibleException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class DoubleImpossibleException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InvalidInputException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		static void printChar(double c);
		static void printInt(double i);
		static void printFloat(double f);
		static void printDouble(double d);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
};

#endif
