#include "PmergeMe.hpp"
#include "PmergeMeDeq.hpp"
#include "isSorted.hpp"
#include <sys/time.h>

double calculateTimeDiff(const struct timeval& start, const struct timeval& end) {
	return (end.tv_sec - start.tv_sec) * 1000000.0 +
		(end.tv_usec - start.tv_usec);
}

int main(int argc, char *argv[]){
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	std::vector<int> original;

	PmergeMe pm;
	PmergeMeDeq pmDeq;

	try {
		pm.makeOriginVector(argc, argv);
		pmDeq.makeOriginDeque(argc, argv);
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	print(pm.getOriginVector());

	struct timeval startDeq, endDeq;
	gettimeofday(&startDeq, NULL);
	pmDeq.devide(pmDeq.getOriginDeque());
	gettimeofday(&endDeq, NULL);
	std::cout << "After(deque): " ;
	print(pmDeq.getResultDeque());

	double durationDeq = calculateTimeDiff(startDeq, endDeq);

	// Vector timing
	struct timeval startVec, endVec;
	gettimeofday(&startVec, NULL);
	pm.devide(pm.getOriginVector());
	gettimeofday(&endVec, NULL);
	std::cout << "After(vector): " ;
	print(pm.getResultVector());

	double durationVec = calculateTimeDiff(startVec, endVec);


	std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::deque : "
			<< std::fixed << durationDeq << " us" << std::endl;


	std::cout << "Time to process a range of " << argc - 1
			<< " elements with std::vector : "
			<< std::fixed << durationVec << " us" << std::endl;


	if (isSorted(pm.getResultVector()))
		std::cout << "Result Vector is sorted.\n";
	else
		std::cout << "Result Vector is not sorted.\n";

	if (isSorted(pmDeq.getResultDeque()))
		std::cout << "Result Deque is sorted.\n";
	else
		std::cout << "Result Deque is not sorted.\n";
	return 0;
}
