#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <fstream>
# include <exception>
# include <map>
# include <algorithm>
# include <utility>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &inputFileName);
		~BitcoinExchange();

		void loadData();
		void readInputFile(const std::string &fileName);

		class FileOpenException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

		class FileReadException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

		class InputFileFormatException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

		class DataFileFormatException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

		class NoDataFormatException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};
	private:
		static const char INPUT_DELIMITER = '|';
		static const char DATABASE_DELIMITER = ',';
		static const size_t DATE_LENGTH = 10;
		static const std::string DATA_FORMAT;
		static const std::string INPUT_FORMAT;
		static const int DAYS_IN_MONTH[12];

		std::string inputFileName;
		std::map<std::string, float> loadedData;
		std::pair<std::string, float> inputData;

		void checkFileFormat(std::ifstream &file, const std::string &expected);

		bool isValidDate(const std::string &date);
		bool parsingDate(const std::string &date, int &year, int &month, int &day);
		bool isLeapYear(int year);

		// load data
		void parsingDataFile(const std::string &line);

		// read input file
		bool parsingInputFile(const std::string &rowLine);
		void printData();

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange& other);

};

#endif
