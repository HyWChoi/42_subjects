#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"
#include <iostream>

// void leaks(){
// 	system("leaks RPG");
// }

int main()
{
	// atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

// int main(){
// 	// atexit(leaks);
// 	std::cout << "\n=== MateriaSource 테스트 ===\n";
// 	IMateriaSource* src = new MateriaSource();
// 	AMateria* ice = new Ice();
// 	AMateria* cure = new Cure();
// 	src->learnMateria(ice);
// 	src->learnMateria(cure);

// 	std::cout << "\n=== 기본 기능 테스트 ===\n";
// 	ICharacter* me = new Character("me");
// 	ICharacter* bob = new Character("bob");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	std::cout << "\n=== 복사 테스트 ===\n";
// 	Character* warrior = new Character("warrior");
// 	tmp = src->createMateria("ice");
// 	warrior->equip(tmp);
// 	Character* warrior_copy = new Character(*warrior);

// 	std::cout << "Original warrior using materia:\n";
// 	warrior->use(0, *bob);
// 	std::cout << "Copied warrior using materia:\n";
// 	warrior_copy->use(0, *bob);

// 	std::cout << "\n=== Unequip과 Floor 테스트 ===\n";
// 	tmp = src->createMateria("ice");
// 	warrior->equip(tmp);
// 	std::cout << "Floor status before unequip:\n";
// 	Floor::getInstance().displayFloor();

// 	warrior->unequip(0);
// 	std::cout << "\nFloor status after unequip:\n";
// 	Floor::getInstance().displayFloor();

// 	std::cout << "Trying to use unequipped materia:\n";
// 	warrior->use(0, *bob);

// 	std::cout << "\n=== 인벤토리 가득 참 테스트 ===\n";
// 	Character* full = new Character("full");
// 	for (int i = 0; i < 5; i++) {
// 		std::cout << "Attempting to equip materia " << i << std::endl;
// 		tmp = src->createMateria("ice");
// 		full->equip(tmp);
// 	}

// 	std::cout << "\n=== Floor 가득 참 테스트 ===\n";
// 	Character* floorTest = new Character("floorTest");
// 	for (int i = 0; i < 10; i++) {
// 		tmp = src->createMateria("ice");
// 		if (tmp) {
// 			floorTest->equip(tmp);
// 			floorTest->unequip(0);
// 		}
// 	}
// 	Floor::getInstance().displayFloor();

// 	std::cout << "\n=== Floor 청소 테스트 ===\n";
// 	Floor::getInstance().cleanFloor();
// 	Floor::getInstance().displayFloor();

// 	std::cout << "\n=== 잘못된 인덱스 테스트 ===\n";
// 	me->use(-1, *bob);
// 	me->use(4, *bob);
// 	me->unequip(-1);
// 	me->unequip(4);

// 	std::cout << "\n=== 알 수 없는 타입 테스트 ===\n";
// 	tmp = src->createMateria("unknown");
// 	if (tmp == NULL)
// 		std::cout << "Unknown type handled correctly (returned NULL)\n";

// 	std::cout << "\n=== 메모리 정리 ===\n";
// 	delete floorTest;
// 	delete warrior_copy;
// 	delete warrior;
// 	delete full;
// 	delete bob;
// 	delete me;
// 	delete src;

// 	Floor::getInstance().cleanFloor();

// 	std::cout << "\n=== 프로그램 종료 ===\n";
// 	return 0;
// }

