#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(){
	this->type = "AMateria";
	std::cout << "AMateria Constructor" << std::endl;
};

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << "AMateria Constructor" << std::endl;
};

AMateria::~AMateria(){
	std::cout << "AMateria Destructor" << std::endl;
};

AMateria::AMateria(const AMateria &other) : type(other.type) {
	std::cout << "AMateria Copy Constructor" << std::endl;
};

AMateria& AMateria::operator=(const AMateria& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "AMateria assighment operator called" << std::endl;
	}
	return *this;
};

std::string const & AMateria::getType() const{
	return this->type;
};

void AMateria::use(ICharacter& target) {
	std::cout << ":" << target.getName() << ":" << "Nothing to use" << std::endl;
};
