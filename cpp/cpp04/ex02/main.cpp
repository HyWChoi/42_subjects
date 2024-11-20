#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

void leaks(){
    system("leaks Animal");
}

int main() {
    atexit(leaks);

    std::cout << "=== Test 1: Basic creation and deletion ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n=== Test 2: Array of animals ===" << std::endl;
    const int arraySize = 10;
    AAnimal* animals[arraySize];

    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    std::cout << "\n=== Test 3: Deep copy test ===" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I love bones!");

    Dog* copiedDog = new Dog(*originalDog);

    originalDog->getBrain()->setIdea(0, "I love sleeping!");

    std::cout << "Original dog's idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;

    return 0;
}
