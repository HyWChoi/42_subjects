#ifndef PMERGEMEDEQ_HPP
#define PMERGEMEDEQ_HPP

#include "PmergeMe.hpp"

class PmergeMeDeq {
	public:
		PmergeMeDeq();
		~PmergeMeDeq();

		void makeOriginDeque(int argc, char *argv[]);
		void devide(const std::deque<unsigned int> &unsignedIntDeque);
		void mergeDequeIntoResult();
		std::deque<unsigned int> generateJacobsthalNumbers(size_t n);

		std::deque<unsigned int> getOriginDeque();
		std::deque<unsigned int> getResultDeque();

		std::deque<Node> makeNodeDeque(const std::deque<unsigned int> &unsignedIntDeque);
		std::deque<unsigned int> makeNewUnsignedIntDequeWithMax(const std::deque<Node> &nodeDeque);
		void makeFanningGroup(const std::deque<Node> &nodeDeque);

		class InvalidInputException : public std::exception  {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::deque<unsigned int> originDeque;
		std::deque<unsigned int> resultDeque;
		std::deque<unsigned int> fanningDeque;

		PmergeMeDeq(const PmergeMeDeq &other);
		PmergeMeDeq &operator=(const PmergeMeDeq &other);
};

#endif
