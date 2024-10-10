/*
Author: Fabiola Li Wu
Course: CSCI-23500
Date: 02/20/2024

Creatioin of the Cavern class and implementation of it.
*/
#include "Cavern.hpp"
#include "cmath"

/**
  Default constructor.
  Default-initializes all private members. 
*/
Cavern::Cavern(){
  level_sum_ = 0;
  tame_count_ = 0;
}

/**
  * @param   :   A reference to a Creature entering the Cavern
  * @post    :   If the given Creature is not already in the Cavern, add Creature to the Cavern and updates the level sum and the tame Creature count if the creature is tame.
  * @return  :   returns true if a Creature was successfully added to the Cavern, false otherwise
            :   Hint: Use the above definition of equality will help determine if a Creature is already in the Cavern
*/
bool Cavern::enterCavern(const Creature& creature){

// if item is in bag,then return false
  for(int i = 0; i < item_count_; i++){
    if(items_[i] == creature)
      return false;
  }

  // if is added then sum level and if is tame then counter
  if(add(creature)){
    level_sum_ += creature.getLevel();
    if(creature.isTame())
      tame_count_ ++;
    return true;
  }
  return false;
}


/** 
  * @param   :   A  reference to a Creature leaving the Cavern
  * @return  :  returns true if a creature was successfully removed from the Cavern (i.e. items_), false otherwise
  * @post    :    removes the creature from the Cavern and updates the level sum. 
                  If the Creature is tame it also updates the tame count.
**/
bool Cavern::exitCavern(const Creature &leaving){
  int removeLevel = leaving.getLevel();
  bool removeTame = leaving.isTame();

// if can be removed, then update sum and tame
  if(remove(leaving)){
    level_sum_ -= removeLevel;
    if(removeTame)
      tame_count_ --;
    return true;
  }
  return false;
}

 /** 
  * @return   :  The integer level count of all the creatures currently in the Cavern
  **/
int Cavern::getLevelSum() const{
    return level_sum_;
}

/**
  * @return   :  The average level (int) of all the creatures in the Cavern
  * @post     :  Computes the average level (double) of the Cavern rounded to the NEAREST integer.
  **/
int Cavern::calculateAvgLevel()const{
  if(!isEmpty())
    return ((int)(round((double)level_sum_ / (double)item_count_)));
  return 0;
}

/**
  * @return   :  The integer count of tame Creatures in the Cavern
  **/
int Cavern::getTameCount() const{
    return tame_count_;
}

/**
  * @return   :  The percentage (double) of all the tame creatures in the Cavern
  * @post     :   Computes the percentage of tame creatures in the Cavern rounded up to 2 decimal places.
  **/
double Cavern::calculateTamePercentage() const{
  if(!isEmpty()){
    int hundred = 100, tt = 10000;
    double percentage = ((double)tame_count_ / (double)item_count_  * (double)tt);
    int percentage2 = ceil(percentage);
    return (percentage2 / (double)hundred);
  }
  return 0;
}  

/**
  * @param  :   A reference to a string representing a creature Category with value in ["UNKNOWN", "UNDEAD", "MYSTICAL", "ALIEN"]
  * @return  :  An integer tally of the number of creatures in the Cavern of the given category. 
              If the argument string does not match one of the expected category values, the tally is zero. 
              NOTE: no pre-processing of the input string necessary, only uppercase input will match.
**/
int Cavern::tallyCategory(const std::string& category) const{
  int tally = 0;
  for(int i = 0; i < item_count_; i++){
    if(items_[i].getCategory() == category)
      tally ++;
  }
  return tally;
}
    
/**
    @param  :   An integer representing the level threshold of the creatures to be removed from the Cavern, with default value 0
    @post   :   Removes all creatures from the Cavern whose level is less than the given level. If no level is given, removes all creatures from the Cavern. Ignore negative input.
    @return :   The number of creatures removed from the Cavern
*/
int Cavern::releaseCreaturesBelowLevel(const int level){
  int counter = 0;

  // check if is greater than 0 and if so then check if level is lower than parameter and if so delete from arraybag
    if(level > 0){
      for(int i = 0; i < item_count_; i++){
        if(items_[i].getLevel() < level){
          exitCavern(items_[i]);
          counter ++;
          i--;
        }
      }
    }
    else if(level < 0)
      return counter;
    else{
      counter = item_count_;
      for(int i = 0; i < item_count_; i++){
        exitCavern(items_[i]);
        i--;
      }
    }
  return counter;
}
    
/**
    @param  : A reference to a string representing a creature Category with a value in ["UNKNOWN", "UNDEAD", "MYSTICAL", "ALIEN"], or default value "ALL" if no category is given
    @post   : Removes all creatures from the Cavern whose category matches the given category. If no category is given, removes all creatures from the Cavern.
    @return : The number of creatures removed from the Cavern
              NOTE: no pre-processing of the input string necessary, only uppercase input will match. If the input string does not match one of the expected category values, do not remove any creatures.
*/
int Cavern::releaseCreaturesOfCategory(const std::string & category){
  int counter = 0;
  //if it is "ALL", then remove every item in the arrayBag
  if(category == "ALL"){
    counter = item_count_;
    for(int i = 0; i < item_count_; i ++){
      exitCavern(items_[i]);
      i--;
    }
    return counter;
  }

  // else, remove what every the parameter gives 
  for(int i = 0; i < item_count_; i ++){
    if(items_[i].getCategory() == category){
      exitCavern(items_[i]);
      counter ++;
      i--;
    }
  }
  return counter;
}
    

/**
  * @post    : Outputs a report of the creatures currently in the Cavern in the form:
              "UNKNOWN: [x]\nUNDEAD: [x]\nMYSTICAL: [x]\nALIEN: [x]\n\nAVERAGE LEVEL: [x]\nTAME:[x]%\n"
              Note that the average level should be rounded to the NEAREST integer, and the percentage of tame creatures in the Cavern should be rounded to 2 decimal places.

              Example output: 
              UNKNOWN: 1
              UNDEAD: 3
              MYSTICAL: 2
              ALIEN: 1

              AVERAGE LEVEL: 5
              TAME: 85.72%
*/
void Cavern::cavernReport()const{
  std::cout << "UNKNOWN: " << tallyCategory("UNKNOWN") << std::endl
            << "UNDEAD: " << tallyCategory("UNDEAD") << std::endl
            << "MYSTICAL: " << tallyCategory("MYSTICAL") << std::endl
            << "ALIEN: " << tallyCategory("ALIEN") << std::endl << std::endl
            << "AVERAGE LEVEL: " << calculateAvgLevel() << std::endl
            << "TAME: " << calculateTamePercentage() << "%" << std::endl;
}