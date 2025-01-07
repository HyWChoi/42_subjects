#ifndef ISSORTED_HPP
# define ISSORTED_HPP

# include <iostream>
# include <vector>
# include <deque>

template <typename Container>
bool isSorted(const Container& container) {
	typedef typename Container::const_iterator Iterator;

	Iterator it = container.begin();
	Iterator end = container.end();

	if (it == end) return true;

	Iterator prev = it;
	++it;

	for (; it != end; ++prev, ++it) {
		if (*it < *prev) {
			return false;
		}
	}
	return true;
}


template <typename Container>
void print(const Container& container) {
	typedef typename Container::const_iterator Iterator;

	for (Iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		Iterator next = it;
		++next;
		if (next != container.end()) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

#endif
