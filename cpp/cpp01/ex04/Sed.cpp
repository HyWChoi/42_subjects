#include "Sed.hpp"

Sed::Sed(const std::string &fileName, const std::string &s1, const std::string &s2)
	: fileName(fileName), originString(s1), replaceString(s2) {};
Sed::~Sed(){};

std::string Sed::getFileName() const {
	return this->fileName;
};
std::string Sed::getOriginString() const {
	return this->originString;
};
std::string Sed::getReplaceString() const {
	return this->replaceString;
};

void Sed::setFileName(std::string str){
	this->fileName = str;
};
void Sed::setOriginString(std::string str){
	this->originString = str;
};
void Sed::setReplceString(std::string str){
	this->replaceString = str;
};

void Sed::sed() {
	std::ifstream inFile(fileName.c_str());
	if (!inFile.is_open()) {
		throw std::runtime_error("Error: could not open input file");
		return ;
	}

	std::string outFileName = fileName + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!outFile.is_open()) {
		inFile.close();
		throw std::runtime_error("Error: could not create output file");
	}

	std::string line;
	while (std::getline(inFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(originString, pos)) != std::string::npos) {
			line = line.substr(0, pos) + replaceString +
				line.substr(pos + originString.length());
			pos += replaceString.length();
		}
		outFile << line;

		if (!inFile.eof()) {
			outFile << std::endl;
		}
	}

	inFile.close();
	outFile.close();
}
