
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
#include "ArrayBag.hpp"
#include <iostream>
#include <cctype>

int main(){
    Creature c1("bob", Creature::UNDEAD, 100, 0, true);
    Creature c2("gg", Creature::UNDEAD, 1010, 4, false);
    Creature c3("john", Creature::UNDEAD, 100, 5, true);
    Creature c4("fisher", Creature::ALIEN, 100, 20, true);
    Creature c5("dogger", Creature::ALIEN, 100, 10, true);
    Creature c6("fa", Creature::ALIEN, 100, 10, true);
    Creature c7("fa", Creature::ALIEN, 100, 10, true);
    Cavern c;
    c.enterCavern(c1);
    c.enterCavern(c2);
    c.enterCavern(c3);
    c.cavernReport();
    //std::cout << "First" << std::endl;
    // c.cavernReport();
    // std::cout << "SUM: " << c.getLevelSum() << std::endl;
    // std::cout << "Tame count: " << c.getTameCount() << std::endl;
    // std::cout << "released: " << c.releaseCreaturesBelowLevel(-1) << std::endl << std::endl << std::endl;
    // c.exitCavern(c1);
    // c.enterCavern(c3);
    // c.enterCavern(c4);
    // c.enterCavern(c5);
    // c.enterCavern(c6);
    // c.enterCavern(c7);
     //c.cavernReport();
     //c.releaseCreaturesOfCategory("ALL");
    //std::cout << "SUM: " << c.getLevelSum() << std::endl;
    
    //c.cavernReport();
    //std::cout << "Average: " << c.calculateAvgLevel() << std::endl;
    //std::cout << std::endl << "released: " << c.releaseCreaturesBelowLevel(20) << std::endl;
    //std::cout << "SUM: " << c.getLevelSum() << std::endl;
    // std::cout << "Average: " << c.calculateAvgLevel() << std::endl;
    //std::cout << "After releasing creatures below level 20" << std::endl<< std::endl;
    //c.cavernReport();
    //std::cout << "Average: " << c.calculateAvgLevel() << std::endl;
    return 0;
}