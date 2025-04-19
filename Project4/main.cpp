/*
CSCI235 Spring 2024
Project 2 - Test
Fabiola Li Wu
Feb 9th 2024
test.cpp will test every class
*/

#include <iostream> 
#include "Creature.hpp"
#include "Cavern.hpp"
//#include "ArrayBag.hpp"
#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"
#include <iostream>
#include <cctype>
int main(){
    // std::cout << "Hello WOrld" << std::endl;
    // Dragon dragon;
    // dragon.display();
    // std::cout << "Eats Myco Morsel? " << dragon.eatMycoMorsel() << std::endl << std::endl;

    // Ghoul ghoul;
    // ghoul.display();
    // std::cout << "Eats Myco Morsel? " << ghoul.eatMycoMorsel() << std::endl << std::endl;

    // Mindflayer mindflayer;
    // mindflayer.display();
    // std::cout << "Eats Myco Morsel? " << mindflayer.eatMycoMorsel() << std::endl << std::endl;

    // Cavern cavern("creatures.csv");
    // //cavern.cavernReport();
    // std::cout << std::endl;

    // //cavern.displayCreatures();

    // std::cout << std::endl;
    // std::string category = "MYSTICAL";
    // cavern.displayCategory(category);
    // category = "ALIEN";
    // cavern.displayCategory(category);
    // category = "UNDEAD";
   // cavern.displayCategory(category);

    //std::cout << cavern.mycoMorselFeast() << std::endl;
//    //Dragon *dragon = new Dragon;
//    //Dragon *dragon2 = new Dragon;
//     //cavern.enterCavern(dragon);
//     cavern.enterCavern(dragon2);
//     // std::cout << dragon2->getLevel() << std::endl;
//     // std::cout << dragon2->getHitpoints() << std::endl;
//     dragon->display();
//     dragon2->display();
//     //std::cout << cavern.getCurrentSize() << std::endl;
//     //std::cout << cavern.calculateAvgLevel() << std::endl;
//     cavern.cavernReport();


//                 name, category, hitpoints, level, tame, decay, faction, transformation
    // Ghoul ghoul("Ghoul1", Creature::UNDEAD, 1,  1, true,  0, Ghoul::NONE, false);
    // std::cout << ghoul.eatMycoMorsel() << std::endl;
    // ghoul.display();
    //Mindflayer(const std::string& name, Category category, int hitpoints, int level, bool tame, std::vector<Projectile> projectiles, bool summoning, std::vector<Variant> affinities)
     Mindflayer mindflayer("BIGBRAIN", Creature::ALIEN, 10, 1, true, {{Mindflayer::PSIONIC, 2},  {Mindflayer::ILLUSIONARY, 3}}, 
     false, {Mindflayer::PSIONIC, Mindflayer::ILLUSIONARY});

    std::cout <<(mindflayer.eatMycoMorsel()? "TRUE" : "FALSE") << std::endl << std::endl;
    mindflayer.display();
    return 0;
}
