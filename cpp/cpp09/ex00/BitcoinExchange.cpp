#include "BitcoinExchange.hpp"

const int BitcoinExchange::DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string BitcoinExchange::DATA_FORMAT = "date,exchange_rate";
const std::string BitcoinExchange::INPUT_FORMAT = "date | value";

BitcoinExchange::BitcoinExchange(){
	this->inputFileName = "";
};

BitcoinExchange::BitcoinExchange(const std::string &inputFileName){
	this->inputFileName = inputFileName;
};

BitcoinExchange::~BitcoinExchange(){
};

void BitcoinExchange::checkFileFormat(std::ifstream &file, const std::string &expected){
	std::string line;
	std::getline(file, line);
	if (file.bad()) throw FileReadException();
	if (line != expected) throw DataFileFormatException();
}

bool BitcoinExchange::parsingDate(const std::string &date, int &year, int &month, int &day){
	std::stringstream ss(date);
	char delimiter;
	return (ss >> year >> delimiter >> month >> delimiter >> day) && ss.eof();
}

bool BitcoinExchange::isLeapYear(int year){
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date){
	if (date.length() != DATE_LENGTH) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	for (size_t i = 0; i < date.length(); i++){
		if (i != 4 && i != 7 && !isdigit(date[i])) return false;
	}

	int year = 0, month = 0, day = 0;

	if (!parsingDate(date, year, month, day)) return false;
	if (year < 1 || month < 1 || month > 12|| day < 1) return false;

	int maxDays = DAYS_IN_MONTH[month - 1];

	if (month == 2 && isLeapYear(year))
		maxDays++;

	return day <= maxDays;
}

void BitcoinExchange::parsingDataFile(const std::string &rowline){
	size_t pos = 0;
	std::string line = rowline;

	size_t start = line.find_first_not_of(" \t");
	size_t end = line.find_last_not_of(" \t");

	pos = line.find(DATABASE_DELIMITER);
	if (pos == std::string::npos) throw DataFileFormatException();

	std::string date = line.substr(0, pos);
	start = date.find_first_not_of(" \t");
	end = date.find_last_not_of(" \t");
	if (!isValidDate(date)) throw DataFileFormatException();

	std::string valueStr = line.substr(pos + 1);
	start = valueStr.find_first_not_of(" \t");
	end = valueStr.find_last_not_of(" \t");
	float value;
	std::stringstream ss(valueStr);
	ss >> value;

	if (ss.fail() || !ss.eof()) throw DataFileFormatException();

	loadedData[date] = value;
}

void BitcoinExchange::loadData(){
	std::ifstream file("data.csv");

	if (!file.is_open()) throw FileOpenException();
	try {
		checkFileFormat(file, DATA_FORMAT);
		std::string line;
		while (std::getline(file, line)){
			if (file.bad()) throw FileReadException();
			parsingDataFile(line);
		}
		if (file.fail() && !file.eof()) throw FileReadException();
	}
	catch (const std::exception& e){
		file.close();
		throw;
	}

	file.close();
}

bool BitcoinExchange::parsingInputFile(const std::string &rowLine){
	size_t pos = 0;
	std::string line = rowLine;

	size_t start = line.find_first_not_of(" \t");
	size_t end = line.find_last_not_of(" \t");

	pos = line.find(INPUT_DELIMITER);
	if (pos == std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	std::string date = line.substr(0, pos - 1);
	start = date.find_first_not_of(" \t");
	end = date.find_last_not_of(" \t");
	if (!isValidDate(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	std::string valueStr = line.substr(pos + 1);
	start = valueStr.find_first_not_of(" \t");
	end = valueStr.find_last_not_of(" \t");
	float value;
	std::stringstream ss(valueStr);
	ss >> value;

	if (ss.fail() || !ss.eof()) {
		std::cout << "Error: not a valid number." << std::endl;
		return false;
	}
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	inputData = std::make_pair(date, value);
	return true;
}

void BitcoinExchange::printData() {
	std::map<std::string, float>::iterator it = loadedData.lower_bound(inputData.first);

	if (it == loadedData.begin() && inputData.first < it->first) {
		std::cout << "Error: no data for " << inputData.first << std::endl;
		return;
	}

	if (it == loadedData.end() || it->first != inputData.first) {
		if (it != loadedData.begin()) {
			--it;
		}
	}

	std::cout << inputData.first << " => " << inputData.second
			<< " = " << it->second * inputData.second << std::endl;
}

void BitcoinExchange::readInputFile(const std::string &fileName){
	std::ifstream file(fileName);

	if (!file.is_open()) throw FileOpenException();
	try {
		checkFileFormat(file, INPUT_FORMAT);
		std::string line;
		while (std::getline(file, line)){
			if (file.bad()) throw FileReadException();
			if (parsingInputFile(line))
				printData();
		}
		if (file.fail() && !file.eof()) throw FileReadException();
	}
	catch (const std::exception& e){
		file.close();
		throw;
	}
}

const char *BitcoinExchange::FileOpenException::what() const throw() {
	return "Failed to open file";
}

const char *BitcoinExchange::FileReadException::what() const throw() {
	return "Failed to read file";
}

const char *BitcoinExchange::InputFileFormatException::what() const throw() {
	return "Invalid format - inputFile";
}

const char *BitcoinExchange::DataFileFormatException::what() const throw() {
	return "Invalid format - dataFile";
}

const char *BitcoinExchange::NoDataFormatException::what() const throw() {
	return "No data found";
}
