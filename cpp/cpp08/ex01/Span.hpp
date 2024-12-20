#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			if (vec.size() + std::distance(begin, end) > maxSize)
				throw std::exception();
			vec.insert(vec.end(), begin, end);
		}

		void addNumber(int n);

		int shortestSpan();
		int longestSpan();

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span is full";
				}
		};

		class SpanNotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span does not have enough numbers";
				}
		};

	private:
		std::vector<int> vec;
		unsigned int maxSize;
};

#endif
