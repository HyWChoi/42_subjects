#include "RPN.hpp"

const std::string RPN::OPERATIONS = "+-*/";

RPN::RPN(){
}

RPN::~RPN(){}

bool RPN::isOperation(const char c) const {
	for (std::string::const_iterator it = OPERATIONS.begin(); it != OPERATIONS.end(); ++it) {
		if (*it == c)
			return true;
	}
	return false;
}

void RPN::doOp(const char c) {
	if (stack.size() < 2) throw InvalidInputException();

	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	if (c == '/') {
		if (b == 0) throw DevideZeroException();
		stack.push(a / b);
	}
	else if (c == '+')
		stack.push(a + b);
	else if (c == '-')
		stack.push(a - b);
	else if (c == '*')
		stack.push(a * b);
}

void RPN::calculate(const std::string &str) {
	if (str.empty()) throw InvalidInputException();

	unsigned int i = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (i % 2 == 0) {
			if (*it == ' ') throw InvalidInputException();

			if (isdigit(*it))
				stack.push(*it - '0');
			else if (isOperation(*it))
				doOp(*it);
			else throw InvalidInputException();
		}
		else {
			if (*it != ' ') throw InvalidInputException();
		}
		i++;
	}

	if (stack.size() != 1)
		throw InvalidInputException();

	std::cout << stack.top() << std::endl;
	stack.pop();
}

const char *RPN::InvalidInputException::what() const throw() {
	return "Invalid input";
}

const char *RPN::DevideZeroException::what() const throw() {
	return "Devide by zero";
}
