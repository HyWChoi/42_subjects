#include "PmergeMe.hpp"
#include "isSorted.hpp"

void PmergeMe::makeOriginVector(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		char* endptr;
		long num = std::strtol(argv[i], &endptr, 10);

		if (*endptr != '\0' || num <= 0 || num > INT_MAX) throw InvalidInputException();
		originVector.push_back(num);
	}
}

std::vector<unsigned int> PmergeMe::getOriginVector(){
	return this->originVector;
}

std::vector<unsigned int> PmergeMe::getResultVector(){
	return resultVector;
}

std::vector<unsigned int> PmergeMe::generateJacobsthalNumbers(size_t n) {
	std::vector<unsigned int> sequence;
	if (n == 0)
		return sequence;
	if (n == 1) {
		sequence.push_back(1);
		return sequence;
	}

	std::vector<unsigned int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

	while (jacobsthal.back() < n) {
		unsigned int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	sequence.push_back(jacobsthal[0]);
	for (size_t i = 1; i < jacobsthal.size() - 1; ++i) {
		unsigned int now = jacobsthal[i];
		while (now > jacobsthal[i - 1]) {
			sequence.push_back(now--);
		}
	}

	for (size_t i = sequence.size(); i < n ; n-- ) {
		sequence.push_back(n);
	}

	return sequence;
}

std::vector<Node> PmergeMe::makeNodeVector(const std::vector<unsigned int> &unsignedIntVector) {
	std::vector<Node> nodeVector;
	for (std::vector<unsigned int>::const_iterator it = unsignedIntVector.begin(); it != unsignedIntVector.end(); it++) {
		Node node;

		unsigned int first = *it;
		unsigned int second = (it + 1 != unsignedIntVector.end()) ? *(it + 1) : 0;

		if (first > second) {
			node.max = first;
			node.min = second;
		} else {
			node.max = second;
			node.min = first;
		}

		nodeVector.push_back(node);
		if (it + 1 != unsignedIntVector.end()) it++;
	}

	return nodeVector;
}

std::vector<unsigned int> PmergeMe::makeNewUnsignedIntVectorWithMax(const std::vector<Node> &nodeVector){
	std::vector<unsigned int> newVector;
	for (std::vector<Node>::const_iterator it = nodeVector.begin(); it != nodeVector.end(); ++it) {
		newVector.push_back(it->max);
	}
	return newVector;
}

void PmergeMe::makeFanningGroup(const std::vector<Node> &nodeVector) {
	std::vector<unsigned int> tmpVec;
	for (std::vector<unsigned int>::const_iterator it = resultVector.begin(); it != resultVector.end(); ++it) {
		for (std::vector<Node>::const_iterator nodeIt = nodeVector.begin(); nodeIt != nodeVector.end(); ++nodeIt) {
			if (*it == nodeIt->max) {
				tmpVec.push_back(nodeIt->min);
				break ;
			}
		}
	}

	std::vector<unsigned int> JacobsthalNumbs = generateJacobsthalNumbers(tmpVec.size());
	int i = 0;
	for (std::vector<unsigned int>::const_iterator it = tmpVec.begin(); it != tmpVec.end() && tmpVec.size(); ++it) {
		fanningVector.push_back(tmpVec[JacobsthalNumbs[i++] - 1]);
	}
}

void PmergeMe::mergeVectorIntoResult() {
	while (!fanningVector.empty()) {
		unsigned int value = fanningVector.front();
		fanningVector.erase(fanningVector.begin());

		std::vector<unsigned int>::iterator insertPos = std::lower_bound(
			resultVector.begin(),
			resultVector.end(),
			value
		);

		if (value != 0) {
			resultVector.insert(insertPos, value);
			std::cout << "inserted value : " << value << std::endl;
		};
	}
}

void PmergeMe::devide(const std::vector<unsigned int> &unsignedIntVector) {
	std::vector<Node> nodeVector = makeNodeVector(unsignedIntVector);
	if (nodeVector.size() == 1) {
		if (nodeVector.begin()->min != 0)
			resultVector.push_back(nodeVector.begin()->min);
		resultVector.push_back(nodeVector.begin()->max);
		return ;
	}
	else {
		std::vector<unsigned int> maxValueVector = makeNewUnsignedIntVectorWithMax(nodeVector);
		devide(maxValueVector);
	}

	makeFanningGroup(nodeVector);
	mergeVectorIntoResult();
}

const char *PmergeMe::InvalidInputException::what() const throw() {
	return "Invalid input";
}

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};
