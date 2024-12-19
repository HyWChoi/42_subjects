#ifndef EAASYFIND_HPP
#define EAASYFIND_HPP

// vector/list/map/and so forth
# include <algorithm>
# include <iostream>
# include <exception>
# include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif
