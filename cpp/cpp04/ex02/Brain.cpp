#include "Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "Brain Constructor" << std::endl;
};

Brain::~Brain(){
	std::cout << "Brain Destructor" << std::endl;
};

Brain::Brain(const Brain& other){
	*this = other;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
};

Brain& Brain::operator=(const Brain& other){
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
		std::cout << "Brain assighment operator called" << std::endl;
	}
	return *this;
};

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
	std::cout << "Invalid index" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return "Invalid index";
}
