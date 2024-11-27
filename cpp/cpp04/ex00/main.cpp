#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

void leaks()
{
    system("leaks Animal");
}

int main() {
    std::cout << "\n=== Testing Animal Hierarchy ===\n" << std::endl;
    
    // Test 1: Basic animal creation and sounds
    std::cout << "Test 1: Basic animal creation and sounds" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    meta->makeSound();
    dog->makeSound();
    cat->makeSound();
    
    // Cleanup
    delete meta;
    delete dog;
    delete cat;
    
    // Test 2: WrongAnimal hierarchy
    std::cout << "\nTest 2: WrongAnimal hierarchy" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrong animal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "wrong cat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();  // Will make wrong animal sound!
    
    // Cleanup
    delete wrongAnimal;
    delete wrongCat;
    
    // Test 3: Direct object creation
    std::cout << "\nTest 3: Direct object creation" << std::endl;
    {
        Dog directDog;
        Cat directCat;
        
        std::cout << "\nDirect object sounds:" << std::endl;
        directDog.makeSound();
        directCat.makeSound();
    }

    return 0;
}
