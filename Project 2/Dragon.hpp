/*
CSCI235 Spring 2024
Project 2 - Test
Fabiola Li Wu
Feb 9th 2024
Dragons.hpp declares Dragons derived class along with its members and methods
*/
#ifndef Dragon_hpp
#define Dragon_hpp
#include "Creature.hpp"
using namespace std;

// declaration of Dragon derived class
class Dragon: public Creature{
public:
    enum Element {NONE, FIRE, WATER, EARTH, AIR};
    Dragon();
    Dragon(const string &name, Category category= MYSTICAL, int hitpoints = 1, int level = 1, bool tame = false,
            Element element = NONE, int heads = 1, bool fly = false);
    std::string getElement() const;
    void setElement(const Element&);
    int getNumberOfHeads() const;
    bool setNumberOfHeads(const int&);
    bool getFlight() const;
    void setFlight(const bool& fly);
    
private:
    Element affinity_;
    int num_heads_;
    bool can_fly_;
};

#endif /* Dragon_hpp */
