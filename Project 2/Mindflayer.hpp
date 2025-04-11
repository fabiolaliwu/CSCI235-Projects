/*
CSCI235 Spring 2024
Project 2 
Fabiola Li Wu
Feb 9th 2024
Mindflayer.hpp declares Mindflayer derived class along with its members and methods
*/
#ifndef Mindflayer_hpp
#define Mindflayer_hpp
#include "Creature.hpp"
#include <stdio.h>
#include <vector>
using namespace std;

// Mindflayer class
class Mindflayer: public Creature{
public:
    enum Variant {PSIONIC, TELEPATHIC, ILLUSIONARY};
    struct Projectile
    {
        Variant type_;
        int quantity_;
    };
    Mindflayer();
    Mindflayer(const string &name, Category category = ALIEN, int hitpoints = 1, int level = 1, bool tame = false,
               vector <Projectile> projectile = {}, bool summon = false, vector <Variant> affinities = {});
    vector <Projectile> getProjectiles()const;
    void setProjectiles(const vector<Projectile>&);
    bool getSummoning() const;
    void setSummoning(const bool &);
    vector <Variant> getAffinities() const;
    void setAffinities(const vector<Variant> &);
    string variantToString(const Variant &);
    
private:
    vector <Projectile> projectiles_;
    vector <Variant> affinities_;
    bool summoning_;
};

#endif /* Mindflayer_hpp */