#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>

class RPN {
	public:
		RPN();
		~RPN();
		void calculate(const std::string &str);

		class InvalidInputException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

		class DevideZeroException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::stack<int> stack;
		static const std::string OPERATIONS;
		bool isOperation(const char c) const;
		void doOp(const char c);

		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
};

#endif
