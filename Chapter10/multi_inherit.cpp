#include "debug.h"

#include <cstddef>
#include <format>
#include <iostream>
#include <unistd.h>

// One solution to solve the `Diamond inheritance` to declare `Abstract class` as interface class
class Animal
{
public:

    // But can use `virtual base class` to avoid ambiguity, with Polymorphism work correctly and not need to manually
    // choose version.
    virtual void sleep() { std::cout << "Sleep ............" << std::endl; }

    // Using abstract to avoid ambiguity
    virtual void live() = 0;
};

class Dog : virtual public Animal
{
public:

    // Declaration Middle class self virtual method
    void         bark() {}

    virtual void eat() { std::cout << "Dog eat" << std::endl; }

    // Implement pure virtual  interface
    void         live() override { std::cout << "Dog live" << std::endl; }

    // Implement virtual method
    void         sleep() override { std::cout << "Sleep Dog version." << std::endl; }

    int          m_dog;
};

class Bird : virtual public Animal
{
public:

    // Declaration Middle class self virtual method
    void         fly() {}

    virtual void eat() { std::cout << "Bird eat" << std::endl; }

    // Implement pure virtual  interface
    void         live() override { std::cout << "Bird live" << std::endl; }

    // Implement virtual method
    void         sleep() override { std::cout << "Sleep Bird version." << std::endl; }

    int          m_bird;
};

class DogBird : public Dog, public Bird
{
public:

    void dog_b() {}

    // Diamond inheritance
    /**
     * @brief Case 1, If base class exist a `virtual method()`, not use `virtual inheritance`
     * @brief Solution: solve by  manually set override version, But none Polymorphism
     * @brief If wanna use Polymorphism, compiler will error.
     */

    /**
     * @brief Solve by `virtual inheritance` .
     *
     */
    void sleep() override { std::cout << "Sleep use Bird version." << std::endl; }

    /**
     * @brief Case 2, base class is just a abstract class, only as interface.
     *
     */
    void live() override { std::cout << "Dogbird version live()." << std::endl; }
};

int main()

{
    // Test multi inherit
    std::cout << FMT("Test inherit class size: ", RED) << std::endl;
    std::cout << "Size of Derived class DogBird: " << sizeof(DogBird) << " Bytes. " << std::endl;

    // Test Ambiguity
    std::cout << FMT("Test Diamond inheritance Ambiguity", RED) << std::endl;
    Animal *animal = nullptr;
    Dog    *dog    = new Dog();
    Bird   *bird   = new Bird();

    std::cout << "Base class with Polymorphism." << std::endl;
    animal = new DogBird();
    animal->sleep();
    animal->live();

    dog->sleep();
    dog->live();

    return 0;
}