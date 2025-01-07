#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>

class RPN {
	public:
		RPN(const std::string &str);
		int getResult() const;

	private:
		static const std::string OPERATORS;
		std::string originStr;
		int result;
		std::list<int> list;

		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
};

#endif
