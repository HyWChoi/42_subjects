#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack() : std::stack<T>(){
			std::cout << "MutantStack default constructor" << std::endl;
		};
		MutantStack(MutantStack const &other) : std::stack<T>(other){
			std::cout << "MutantStack copy constructor" << std::endl;
		};
		MutantStack &operator=(MutantStack const &other){
			std::cout << "MutantStack assignation operator" << std::endl;
			if (this == &other)
				return *this;
			std::stack<T>::operator=(other);
			return *this;
		};
		~MutantStack(){
			std::cout << "MutantStack destructor" << std::endl;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin(){
			return std::stack<T>::c.begin();
		};
		iterator end(){
			return std::stack<T>::c.end();
		};

		const_iterator begin() const{
			return std::stack<T>::c.begin();
		};
		const_iterator end() const{
			return std::stack<T>::c.end();
		};
};

#endif
