/*
CSCI235 Spring 2024
Project 6 - Cavern
Fabiola Li Wu
April 5th 2024
main.cpp tests and debugs all the classes
*/

#include <iostream>
// #include "ArrayBag.hpp"
#include "Cavern.hpp"
#include "Creature.hpp"
#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"

int main()
{
    // std::cout << "HELLO " << std::endl;

    // Dragon dragon;
    // dragon.addAttack(1);
    // dragon.addAttack(2);

    // std::queue<Attack> attack_queue = dragon.getAttackQueue();
    // // std::cout << attack_queue.size() << std::endl;

    // std::stack<int> integerNumbers;
    // integerNumbers.push(2);
    // integerNumbers.push(21);
    // integerNumbers.push(3);
    // integerNumbers.push(33);
    // integerNumbers.push(99);
    // // std::cout << integerNumbers.top() << std::endl;

    // std::stack<int> transfer;
    // while (!integerNumbers.empty())
    // {
    //     transfer.push(integerNumbers.top());
    //     std::cout << transfer.top() << " ";
    //     integerNumbers.pop();
    // }
    // for (int i = 0; i < transfer.size(); i++)
    //     std::cout << transfer.top() << " ";
    // std::cout << std::endl;

    // Dragon dragon("NAME", Creature::MYSTICAL, 2, 3, false, Dragon::NONE, 3, 3);
    // dragon.setCategory(Creature::ALIEN);
    // // std::cout << dragon.getElement() << std::endl;
    // // dragon.setElement(Dragon::AIR);
    // dragon.addAttack(3);
    // std::cout << std::endl;

    // dragon.setCategory(Creature::MYSTICAL);
    // // std::cout << dragon.getElement() << std::endl;
    // // dragon.setElement(Dragon::AIR);
    // dragon.addAttack(3);
    // std::cout << std::endl;

    // dragon.setCategory(Creature::UNDEAD);
    // // std::cout << dragon.getElement() << std::endl;
    // dragon.setElement(Dragon::AIR);
    // dragon.addAttack(3);
    // std::cout << std::endl;

    // dragon.setCategory(Creature::UNKNOWN);
    // // std::cout << dragon.getElement() << std::endl;
    // dragon.setElement(Dragon::AIR);
    // dragon.addAttack(3);
    // std::cout << std::endl;

    // Ghoul ghoul;
    //  //ghoul.setFaction(Ghoul::NONE);
    //  ghoul.setCategory(Creature::ALIEN);
    //  ghoul.addAttack(2);

    // ghoul.setCategory(Creature::MYSTICAL);
    // ghoul.setFaction(Ghoul::NONE);
    // ghoul.addAttack(1);

    // ghoul.setCategory(Creature::UNDEAD);
    // ghoul.addAttack(1);

    // ghoul.setCategory(Creature::UNKNOWN);
    // ghoul.addAttack(1);

    // ghoul.setFaction(Ghoul::FLESHGORGER);
    // ghoul.addAttack(3);

    // ghoul.setFaction(Ghoul::NONE);
    // ghoul.addAttack(3);

    // ghoul.setFaction(Ghoul::SHADOWSTALKER);
    // ghoul.addAttack(3);

    // ghoul.setFaction(Ghoul::PLAGUEWEAVER);
    // ghoul.addAttack(3);

    // Mindflayer mindflayer;
    // mindflayer.addAttack(3);

    Cavern cavern("creatures.csv");
    cavern.displayCreatures();
    cavern.initializeAlienStack();
    cavern.initializeMysticalStack();
    cavern.initializeUndeadStack();
    cavern.initializeUnknownStack();
    std::stack<Creature *> alienStack = cavern.getAlienStack();
    while (!alienStack.empty())
    {
        std::cout << alienStack.top()->getName() << std::endl;
        alienStack.pop();
    }
    cavern.initializeAlienStack();
    // cavern.clearAlienStack();
    // cavern.clearMysticalStack();
    // cavern.clearUndeadStack();
    // cavern.clearUnknownStack();
    std::stack<Creature *> example3 = cavern.getAlienStack();
    std::stack<Creature *> example2 = cavern.getMysticalStack();
    std::stack<Creature *> example1 = cavern.getUndeadStack();
    std::stack<Creature *> example = cavern.getUnknownStack();

    std::cout << example3.size() << std::endl;
    std::cout << example2.size() << std::endl;
    std::cout << example1.size() << std::endl;
    std::cout
        << example.size() << std::endl
        << std::endl
        << std::endl
        << std::endl;
    cavern.setAttacks({});

    // cavern.clearAlienStack();
    example3 = cavern.getAlienStack();
    std::cout << "\nSIZE: " << example3.size() << std::endl;
    while (!example3.empty())
    {
        std::cout << example3.top()->getName() << std::endl;
        example3.pop();
    }

    Dragon dragon;
    std::queue<Attack> attackQueue = dragon.getAttackQueue();
    while (!attackQueue.empty())
    {
        std::cout << attackQueue.front().name_ << " ";
        attackQueue.pop();
    }

    // std::cout << "\nSIZE: "
    //           << example3.size() << std::endl;

    // std::cout << "GONE" << std::endl;
    // std::stack<Creature *> result = cavern.getAlienStack();
    // std::cout << "\n"
    //           << result.size() << std::endl;

    // std::queue<int> numbers;
    // numbers.push(1);
    // numbers.push(2);
    // numbers.push(3);
    // numbers.push(4);
    // numbers.push(5);
    // while (!numbers.empty())
    // {
    //     std::cout << numbers.front() << " ";
    //     numbers.pop();
    // }
    // std::cout << std::endl;

    // std::queue<Attack> attacks = cavern.getAttackQueue();
    // while (!attacks.empty())
    // {
    //     std::cout << attacks.front().name_ << std::endl;
    //     attacks.pop();
    // }
    return 0;
}
// Creature.hpp  Dragon.cpp   Dragon.hpp  Dragon.o  Ghoul.cpp Ghoul.hpp Ghoul.o Mindflayer.cpp  Mindflayer.hpp  Mindflayer.o  main  main.cpp  main.o