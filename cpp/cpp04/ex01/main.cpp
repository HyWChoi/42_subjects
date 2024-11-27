#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\n=== Basic Animal Creation and Deletion Test ===\n" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        
        std::cout << "\nMaking sounds before deletion:" << std::endl;
        dog->makeSound();
        cat->makeSound();
        
        delete dog;
        delete cat;
    }
    
    std::cout << "\n=== Array of Animals Test ===\n" << std::endl;
    {
        const int arraySize = 4;  // Half dogs, half cats
        Animal* animals[arraySize];
        
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
        
        // Make them all sound
        std::cout << "\nMaking all animals sound:" << std::endl;
        for (int i = 0; i < arraySize; i++) {
            std::cout << "Animal " << i + 1 << ": ";
            animals[i]->makeSound();
        }
        
        // Delete all animals
        std::cout << "\nDeleting all animals:" << std::endl;
        for (int i = 0; i < arraySize; i++) {
            delete animals[i];
        }
    }
    
    std::cout << "\n=== Deep Copy Test ===\n" << std::endl;
    {
        std::cout << "Creating original dog:" << std::endl;
        Dog originalDog;
        
        // Set some ideas for the original dog
        Brain* originalBrain = originalDog.getBrain();
        originalBrain->setIdea(0, "I love bones!");
        originalBrain->setIdea(1, "I want to chase cats!");
        
        std::cout << "\nCreating copy dog:" << std::endl;
        Dog copyDog = originalDog;  // Should trigger deep copy
        
        // Verify the ideas were copied
        Brain* copyBrain = copyDog.getBrain();
        std::cout << "\nVerifying deep copy:" << std::endl;
        std::cout << "Original dog's first idea: " << originalBrain->getIdea(0) << std::endl;
        std::cout << "Copy dog's first idea: " << copyBrain->getIdea(0) << std::endl;
        
        // Modify copy's idea and verify original remains unchanged
        copyBrain->setIdea(0, "I love sleeping!");
        std::cout << "\nAfter modifying copy:" << std::endl;
        std::cout << "Original dog's first idea: " << originalBrain->getIdea(0) << std::endl;
        std::cout << "Copy dog's first idea: " << copyBrain->getIdea(0) << std::endl;
    }
    
    std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        
        // Set some ideas for dog1
        Brain* brain1 = dog1.getBrain();
        brain1->setIdea(0, "Original idea");
        
        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "Dog1's idea: " << brain1->getIdea(0) << std::endl;
        std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
        
        // Test assignment operator
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