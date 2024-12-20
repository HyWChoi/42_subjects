#include "Span.hpp"

/**
class Span {
	public:
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			if (vec.size() + std::distance(begin, end) > maxSize)
				throw std::exception();
			vec.insert(vec.end(), begin, end);
		}

		void addNumber(int n);

		int shortestSpan();
		int longestSpan();
	private:
		std::vector<int> vec;
		unsigned int maxSize;
};
*/

Span::Span(){
	std::cout << "Span default constructor" << std::endl;
	this->maxSize = 0;
	this->vec = std::vector<int>();
}

Span::Span(unsigned int n){
	std::cout << "Span constructor with n" << std::endl;
	this->maxSize = n;
	this->vec = std::vector<int>();
}

Span::Span(Span const &other){
	std::cout << "Span copy constructor" << std::endl;
	this->maxSize = other.maxSize;
	this->vec = other.vec;
}

Span& Span::operator=(Span const &other){
	std::cout << "Span assignation operator" << std::endl;
	if (this == &other)
		return *this;
	this->maxSize = other.maxSize;
	this->vec = other.vec;
	return *this;
}

Span::~Span(){
	std::cout << "Span destructor" << std::endl;
}

void Span::addNumber(int n){
	if (vec.size() + 1 > maxSize) throw SpanFullException();
	vec.push_back(n);
}

int  Span::shortestSpan(){
	if (vec.size() < 2) throw SpanNotEnoughNumbersException();
	std::vector<int> sorted = vec;
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size() - 1; i++){
		if (sorted[i + 1] - sorted[i] < min)
			min = sorted[i + 1] - sorted[i];
	}
	return min;
}

int  Span::longestSpan(){
	if (vec.size() < 2) throw SpanNotEnoughNumbersException();
	std::vector<int> sorted = vec;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}
