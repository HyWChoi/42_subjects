#include "PmergeMeDeq.hpp"
#include "isSorted.hpp"

void PmergeMeDeq::makeOriginDeque(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		char* endptr;
		long num = std::strtol(argv[i], &endptr, 10);

		if (*endptr != '\0' || num <= 0 || num > INT_MAX) throw InvalidInputException();
		originDeque.push_back(num);
	}
}

std::deque<unsigned int> PmergeMeDeq::getOriginDeque() {
	return this->originDeque;
}

std::deque<unsigned int> PmergeMeDeq::getResultDeque() {
	return resultDeque;
}

std::deque<unsigned int> PmergeMeDeq::generateJacobsthalNumbers(size_t n) {
	std::deque<unsigned int> sequence;
	if (n == 0)
		return sequence;
	if (n == 1) {
		sequence.push_back(1);
		return sequence;
	}

	std::deque<unsigned int> jacobsthal;
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

	for (size_t i = sequence.size(); i < n; n--) {
		sequence.push_back(n);
	}

	return sequence;
}

std::deque<Node> PmergeMeDeq::makeNodeDeque(const std::deque<unsigned int> &unsignedIntDeque) {
	std::deque<Node> nodeDeque;
	for (std::deque<unsigned int>::const_iterator it = unsignedIntDeque.begin(); it != unsignedIntDeque.end(); it++) {
		Node node;

		unsigned int first = *it;
		unsigned int second = (it + 1 != unsignedIntDeque.end()) ? *(it + 1) : 0;

		if (first > second) {
			node.max = first;
			node.min = second;
		} else {
			node.max = second;
			node.min = first;
		}

		nodeDeque.push_back(node);
		if (it + 1 != unsignedIntDeque.end()) it++;
	}

	return nodeDeque;
}

std::deque<unsigned int> PmergeMeDeq::makeNewUnsignedIntDequeWithMax(const std::deque<Node> &nodeDeque) {
	std::deque<unsigned int> newDeque;
	for (std::deque<Node>::const_iterator it = nodeDeque.begin(); it != nodeDeque.end(); ++it) {
		newDeque.push_back(it->max);
	}
	return newDeque;
}

void PmergeMeDeq::makeFanningGroup(const std::deque<Node> &nodeDeque) {
	std::deque<unsigned int> tmpDeq;
	for (std::deque<unsigned int>::const_iterator it = resultDeque.begin(); it != resultDeque.end(); ++it) {
		for (std::deque<Node>::const_iterator nodeIt = nodeDeque.begin(); nodeIt != nodeDeque.end(); ++nodeIt) {
			if (*it == nodeIt->max) {
				if (nodeIt->min != 0)
					tmpDeq.push_back(nodeIt->min);
				break ;
			}
		}
	}
	std::deque<unsigned int> JacobsthalNumbs = generateJacobsthalNumbers(tmpDeq.size());
	int i = 0;
	for (std::deque<unsigned int>::const_iterator it = tmpDeq.begin(); it != tmpDeq.end() && tmpDeq.size(); ++it) {
		fanningDeque.push_back(tmpDeq[JacobsthalNumbs[i++] - 1]);
	}
}

void PmergeMeDeq::mergeDequeIntoResult() {
	while (!fanningDeque.empty()) {
		unsigned int value = fanningDeque.front();
		fanningDeque.pop_front();

		if (value != 0 && value <= resultDeque[0]) {
			resultDeque.push_front(value);
			continue ;
		}

		std::deque<unsigned int>::iterator insertPos = std::lower_bound(
			resultDeque.begin(),
			resultDeque.end(),
			value
		);

		if (value != 0) {
			// std::cout << "inserted" << value << std::endl;
			resultDeque.insert(insertPos, value);
		}
	}
}

void PmergeMeDeq::devide(const std::deque<unsigned int> &unsignedIntDeque) {
	std::deque<Node> nodeDeque = makeNodeDeque(unsignedIntDeque);
	if (nodeDeque.size() == 1) {
		if (nodeDeque.begin()->min != 0)
			resultDeque.push_back(nodeDeque.begin()->min);
		resultDeque.push_back(nodeDeque.begin()->max);
		return;
	}
	else {
		std::deque<unsigned int> maxValueDeque = makeNewUnsignedIntDequeWithMax(nodeDeque);
		devide(maxValueDeque);
	}

	makeFanningGroup(nodeDeque);
	mergeDequeIntoResult();
}

const char *PmergeMeDeq::InvalidInputException::what() const throw() {
	return "Invalid input";
}

PmergeMeDeq::PmergeMeDeq() {}
PmergeMeDeq::~PmergeMeDeq() {}
