/*
Author: Fabiola Li Wu
Course: CSCI-23500
Date: 02/20/2024

Cavern.hpp declares the Cavern class along with its private and public members
*/

#ifndef CAVERN_HPP_
#define CAVERN_HPP_
#include <iostream>
#include <vector>
#include "Creature.hpp"
#include "ArrayBag.hpp"
#include <string>
#include <cmath>

class Cavern: public ArrayBag<Creature>{
public:
    Cavern();
    bool enterCavern(const Creature&);
    bool exitCavern(const Creature &);
    int getLevelSum() const;
    int calculateAvgLevel()const;
    int getTameCount() const;
    double calculateTamePercentage() const;
    int tallyCategory(const std::string&) const;
    int releaseCreaturesBelowLevel(const int);
    int releaseCreaturesOfCategory(const std::string &);
    void cavernReport()const;
    
private:
    int level_sum_;
    int tame_count_;
};

#endif