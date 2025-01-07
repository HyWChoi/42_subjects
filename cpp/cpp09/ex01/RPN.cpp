#include "RPN.hpp"

const std::string RPN::OPERATORS = "+-*/";

RPN::RPN(const std::string &str){
	this->originStr = str;
}

int RPN::getResult() const{

}
