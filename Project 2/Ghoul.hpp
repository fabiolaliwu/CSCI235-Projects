/*
CSCI235 Spring 2024
Project 2 
Fabiola Li Wu
Feb 9th 2024
Ghoul.hpp declares Ghoul derived class along with its members and methods
*/
#include "Creature.hpp"
#ifndef Ghoul_hpp
#define Ghoul_hpp
#include <stdio.h>
using namespace std;

// Ghoul class
class Ghoul: public Creature{
public:
    enum Faction {NONE, FLESHGORGER, SHADOWSTALKER, PLAGUEWEAVER};
    Ghoul();
    Ghoul(const std::string &name, Category category = UNDEAD, int hitpoints = 1, int level = 1, bool tame = false,
          int decay = 0, Faction faction = NONE, bool transform = false);
    int getDecay() const;
    void setDecay(const int&);
    std::string getFaction() const;
    void setFaction(const Faction&);
    bool getTransformation() const;
    void setTransformation(const bool&);
    
private:
    int level_of_decay_;
    Faction faction_;
    bool can_transform_;
};

#endif /* Ghoul_hpp */
