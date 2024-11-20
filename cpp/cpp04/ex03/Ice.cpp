#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice Constructor" << std::endl;
};

Ice::Ice(std::string const & type) : AMateria(type){
	std::cout << "Ice Constructor" << std::endl;
};

Ice::~Ice(){
	std::cout << "Ice Destructor" << std::endl;
};

Ice::Ice(const Ice &other) : AMateria(other.type) {
	std::cout << "Ice Copy Constructor" << std::endl;
};

Ice& Ice::operator=(const Ice& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "Ice assighment operator called" << std::endl;
	}
	return *this;
};

AMateria* Ice::clone() const{
	return new Ice(*this);
};

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
