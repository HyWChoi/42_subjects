#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <sstream>

template <typename T>
class Array {
	public:
		Array() {
			this->array = NULL;
			this->len = 0;
		};
		Array(unsigned int n){
			this->array = new T[n];
			this->len = n;
		};
		~Array(){
			delete[] this->array;
		};
		Array(Array const &src){
			this->array = new T[src.len];
			this->len = src.len;
			for (unsigned int i = 0; i < src.len; i++) {
				this->array[i] = src.array[i];
			}
		};
		Array &operator=(Array const &rhs){
			if (this->array) {
				delete[] this->array;
			}
			this->array = new T[rhs.len];
			this->len = rhs.len;
			for (unsigned int i = 0; i < rhs.len; i++) {
				this->array[i] = rhs.array[i];
			}
			return *this;
		};
		T &operator[](unsigned int i){
			if (i >= this->len) {
				throw OutOfLimitsException();
			}
			return this->array[i];
		};
		unsigned int size() const {
			return this->len;
		};
		class OutOfLimitsException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Out of limits";
				};
		};
	private:
		T *array;
		unsigned int len;
};

#endif
