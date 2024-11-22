#include "Sed.hpp"
#include <sstream>

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
    }

    std::string outFileName = fileName + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile.is_open()) {
        inFile.close();
        throw std::runtime_error("Error: could not create output file");
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
    
    size_t pos = 0;
    while ((pos = content.find(originString, pos)) != std::string::npos) {
        content = content.substr(0, pos) + replaceString +
            content.substr(pos + originString.length());
        pos += replaceString.length();
    }
        outFile << content;

    inFile.close();
    outFile.close();
}