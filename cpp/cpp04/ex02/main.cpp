#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\n=== Abstract Class Test ===\n" << std::endl;
    
    // This line should not compile - demonstrates Animal is abstract
    // const AAnimal* meta = new AAnimal();
    
    std::cout << "Creating derived class objects:" << std::endl;
    {
        const AAnimal* dog = new Dog();
        const AAnimal* cat = new Cat();
        
        std::cout << "\nTesting types:" << std::endl;
        std::cout << "Dog type: " << dog->getType() << std::endl;
        std::cout << "Cat type: " << cat->getType() << std::endl;
        
        std::cout << "\nTesting sounds:" << std::endl;
        std::cout << "Dog sound: ";
        dog->makeSound();
        std::cout << "Cat sound: ";
        cat->makeSound();
        
        std::cout << "\nCleaning up:" << std::endl;
        delete dog;
        delete cat;
    }
    
    std::cout << "\n=== Polymorphic Behavior Test ===\n" << std::endl;
    {
        std::cout << "Testing array of animals:" << std::endl;
        const int arraySize = 4;
        AAnimal* animals[arraySize];
        
        // Create half dogs, half cats
        for (int i = 0; i < arraySize; i++) {
            if (i < arraySize / 2) {
                std::cout << "\nCreating Dog " << i + 1 << ":" << std::endl;
                animals[i] = new Dog();
            } else {
                std::cout << "\nCreating Cat " << i - (arraySize / 2) + 1 << ":" << std::endl;
                animals[i] = new Cat();
            }
        }
        
        // Test all animals
        std::cout << "\nTesting all animals:" << std::endl;
        for (int i = 0; i < arraySize; i++) {
            std::cout << "Animal " << i + 1 << " (Type: " << animals[i]->getType() << ") says: ";
            animals[i]->makeSound();
        }
        
        // Cleanup
        std::cout << "\nCleaning up array:" << std::endl;
        for (int i = 0; i < arraySize; i++) {
            delete animals[i];
        }
    }
    
    std::cout << "\n=== Deep Copy Test with Abstract Base ===\n" << std::endl;
    {
        std::cout << "Creating and copying Dog:" << std::endl;
        Dog originalDog;
        originalDog.getBrain()->setIdea(0, "I love bones!");
        
        Dog copyDog = originalDog;
        
        std::cout << "\nVerifying ideas:" << std::endl;
        std::cout << "Original dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy dog's idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
        
        // Modify copy
        copyDog.getBrain()->setIdea(0, "I love sleeping!");
        
        std::cout << "\nAfter modifying copy:" << std::endl;
        std::cout << "Original dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy dog's idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
    }
    
    std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        
        dog1.getBrain()->setIdea(0, "Original idea");
        std::cout << "Before assignment:" << std::endl;
        std::cout << "Dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
        
        dog2 = dog1;
        
        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "Dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    }
    
    // Optional: Memory leak check pause
    std::cout << "\nTests completed. Check for memory leaks.\n" << std::endl;
    // std::cin.get(); // Uncomment to pause for leak checking
    
    return 0;
}
