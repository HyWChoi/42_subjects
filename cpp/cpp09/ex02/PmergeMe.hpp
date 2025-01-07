#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <fstream>
# include <exception>
# include <algorithm>
# include <deque>
# include <vector>
# include <exception>

typedef struct Node {
	unsigned int max;
	unsigned int min;
} Node;

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

		// vec funcs
		void makeOriginVector(int argc, char *argv[]);
		void devide(const std::vector<unsigned int> &unsignedIntVector);
		void mergeVectorIntoResult();
		std::vector<unsigned int> generateJacobsthalNumbers(size_t n);

		std::vector<unsigned int> getOriginVector();
		std::vector<unsigned int> getResultVector();

		std::vector<Node> makeNodeVector(const std::vector<unsigned int> &unsignedIntVector);
		std::vector<unsigned int> makeNewUnsignedIntVectorWithMax(const std::vector<Node> &nodeVector);
		void makeFanningGroup(const std::vector<Node> &nodeVector);

		class InvalidInputException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::vector<unsigned int> originVector;
		std::vector<unsigned int> resultVector;
		std::vector<unsigned int> fanningVector;

		PmergeMe(const PmergeMe &oher);
		PmergeMe &operator=(const PmergeMe &other);

};

#endif
