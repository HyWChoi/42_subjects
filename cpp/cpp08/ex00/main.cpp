#include "easyfind.hpp"

int main()
{
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 5);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 10);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Not found" << std::endl;
		}
	}
	return 0;
}
