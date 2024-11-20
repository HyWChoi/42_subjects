#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure Constructor" << std::endl;
};

Cure::Cure(std::string const & type) : AMateria(type){
	std::cout << "Cure Constructor" << std::endl;
};

Cure::~Cure(){
	std::cout << "Cure Destructor" << std::endl;
};

Cure::Cure(const Cure &other) : AMateria(other.type) {
	std::cout << "Cure Copy Constructor" << std::endl;
};

Cure& Cure::operator=(const Cure& other){
	if (this != &other) {
		this->type = other.type;
		std::cout << "Cure assighment operator called" << std::endl;
	}
	return *this;
};

AMateria* Cure::clone() const{
	return new Cure(*this);
};

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
