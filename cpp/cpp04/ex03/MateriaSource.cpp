#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : learnedCount(0) {
	for (int i = 0; i < 4; i++) {
		templates[i] = NULL;
	}
	std::cout << "MateriaSource const" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource Destructor starting cleanup..." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->templates[i]) {
			std::cout << "Deleting template " << i << ": " << this->templates[i]->getType() << std::endl;
			delete this->templates[i];
			this->templates[i] = NULL;
		}
	}
	std::cout << "MateriaSource Destructor finished" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : learnedCount(0) {
	for (int i = 0; i < 4; i++) {
		if(templates[i])
			delete templates[i];
		templates[i] = NULL;
		if (other.templates[i]) {
			templates[i] = other.templates[i]->clone();
			learnedCount++;
		}
	}
	std::cout << "MateriaSource copy const" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (templates[i]) {
				delete templates[i];
				templates[i] = NULL;
			}
		}

		learnedCount = 0;
		for (int i = 0; i < 4; i++) {
			if (other.templates[i]) {
				templates[i] = other.templates[i]->clone();
				learnedCount++;
			}
		}
		std::cout << "MateriaSource copy assign" << std::endl;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (learnedCount < 4 && m != NULL) {
		for (int i = 0; i < 4; i++) {
			if (templates[i] == NULL) {
				templates[i] = m->clone();
				learnedCount++;
				break;
			}
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (templates[i] && templates[i]->getType() == type) {
			return templates[i]->clone();
		}
	}
	return NULL;
}
