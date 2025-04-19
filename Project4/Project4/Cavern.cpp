/*
CSCI235 Spring 2024
Project 3 - Cavern Class
Fabiola Li Wu
Feb 9th 2024
Taven.cpp declares the Cavern class along with its private and public members
*/
#include "Cavern.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <istream>
#include <sstream>

Cavern::Cavern() : ArrayBag<Creature *>(), level_sum_{0}, tame_count_{0} {
}

bool Cavern::enterCavern(Creature* new_creature) {
  if (getIndexOf(new_creature) == -1) {
    if (add(new_creature)){
      level_sum_ += new_creature->getLevel();
      if (new_creature->isTame()) {
        tame_count_++;
      }
      return true;
    }
  }
  return false;
}

bool Cavern::exitCavern(Creature*  creature_to_remove) {
  if (remove(creature_to_remove)) {
    level_sum_ -= creature_to_remove->getLevel();
    if (creature_to_remove->isTame()) {
      tame_count_--;
    }
    return true;
  }
  return false;
}

int Cavern::getLevelSum() const {
  return level_sum_;
}

int Cavern::calculateAvgLevel() const {
  if (isEmpty()) {
    return 0;
  }
  return round(level_sum_ / getCurrentSize());
}

int Cavern::getTameCount() const {
  return tame_count_;
}

double Cavern::calculateTamePercentage() const {
  if (isEmpty()) {
    return 0;
  }
  double tame_percent = (tame_count_>0) ?  (double(tame_count_) / item_count_) * 100: 0.0;
  // return the tame percentage rounded up to two decimal places

  return std::ceil(tame_percent * 100) / 100;

}

int Cavern::tallyCategory(const std::string& category) const {
  if(category != "UNKNOWN" && category != "UNDEAD" && category != "MYSTICAL" && category != "ALIEN") {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < getCurrentSize(); i++) {
    if (items_[i]->getCategory() == category) {
      count++;
    }
  }
  return count;
}

int Cavern::releaseCreaturesBelowLevel(int level) {
  int count = 0;
  if (level < 0) {
    return 0;
  }
  else if (level == 0) {
    count = getCurrentSize();
    clear();
    return count;
  }
  else {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
      if (items_[i]->getLevel() < level) {
        exitCavern(items_[i]);
        count++;
      }
    }
    return count;
  }
}

int Cavern::releaseCreaturesOfCategory(const std::string& category) {
  int count = 0;
  if (category == "ALL") {
    count = getCurrentSize();
    clear();
    return count;
  }
  else if (category != "UNKNOWN" && category != "UNDEAD" && category != "MYSTICAL" && category != "ALIEN") {
    return 0;
  }
  else {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
    if (items_[i]->getCategory() == category) {
      exitCavern(items_[i]);
      count++;
    }
  }
  return count;
  }
}

void Cavern::cavernReport() const {
  std::cout << "UNKNOWN: " << tallyCategory("UNKNOWN") << std::endl;
  std::cout << "UNDEAD: " << tallyCategory("UNDEAD") << std::endl;
  std::cout << "MYSTICAL: " << tallyCategory("MYSTICAL") << std::endl;
  std::cout << "ALIEN: " << tallyCategory("ALIEN") << std::endl;
  std::cout << std::endl;

  std::cout << "AVERAGE LEVEL: " << calculateAvgLevel() << std::endl;
  std::cout << "TAME: " << calculateTamePercentage() << "%" << std::endl;
} 


/**
    @param: the name of an input file (a string reference)
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
    1. TYPE: An uppercase string [DRAGON, GHOUL, MINDFLAYER]
    2. NAME: An uppercase string
    3. CATEGORY: An uppercase string [ALIEN, MYSTICAL, UNDEAD]
    4. HITPOINTS: A positive integer
    5. LEVEL: A positive integer
    6. TAME: 0 (False) or 1 (True)
    7. ELEMENT/FACTION: Uppercase string or strings representing the ELEMENT (For Dragons), or FACTION (For Ghouls) of the creature. If the creature is of a different subclass, the value will be NONE
    8. HEADS: A positive integer of the number of heads the Dragon has. If the creature is of a different subclass, the value will be 0
    9. FLIGHT/TRANSFORM/SUMMONING: 0 (False) or 1 (True) representing if the creature can fly (Dragons), transform (Ghouls), or summon a Thoughtspawn (Mindflayers).
    10. DECAY: A non-negative integer representing the level of decay of the Ghoul. If the creature is of a different subclass, the value will be 0
    11. AFFINITIES: Only applicable to Mindflayers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Mindflayer with no affinities, or creatures of other subclasses.
    12. PROJECTILES: Only applicable to Mindflayers. PROJECTILES are of the form [PROJECTILE TYPE1]-[QUANTITY];[PROJECTILE TYPE 2]-[QUANTITY] where multiple types of projectiles are separated by a semicolon. The value may be NONE for a Mindflayer with no projectiles, or creatures of other subclasses.
*/
    Cavern::Cavern(const std::string & file): Cavern(){
      //open file to read 
      std::ifstream file_name(file);

      //data needed for subclasses of Creature
      std::string sentence, temp, type, name, categoryString, elementFaction, affinity, projectile, projectileType, projectileQuantityString;
      int hitpoints, level, heads, decay;
      bool tame, flightTransformSummoning;
      std::vector<Mindflayer::Variant> affinities;
      std::vector<Mindflayer::Projectile> projectiles;
      Dragon::Element element;
      Ghoul::Faction faction;
      Creature::Category category;

      // while still gets sentence from file
      while (std::getline(file_name, sentence)){
        std::istringstream streamingSentence(sentence);

        // getline until ',' from streamingSentence and place it in temp;
        // type

        std::getline(streamingSentence, type, ',');

        //name
        std::getline(streamingSentence, name, ',');

        // category
        std::getline(streamingSentence, categoryString, ',');

        //Category {UNKNOWN, UNDEAD, MYSTICAL, ALIEN};
        if(categoryString == "UNKNOWN")
          category = Creature::UNKNOWN;
        else if(categoryString == "UNDEAD")
          category = Creature::UNDEAD;
        else if(categoryString == "MYSTICAL")
          category = Creature::MYSTICAL;
        else if(categoryString == "ALIEN")
          category = Creature::ALIEN;

        // hitpoints
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingHitpoints(temp);
        streamingHitpoints >> hitpoints;

        // level
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingLevel(temp);
        streamingLevel >> level;

        // tame
        std::getline(streamingSentence, temp, ',');
        std::istringstream streaming(temp);
        streaming >> tame;

        // elementFaction
        std::getline(streamingSentence, elementFaction, ','); 
        if(elementFaction == "NONE")
          element = Dragon::NONE;
        else if(elementFaction == "FIRE")
          element = Dragon::FIRE;
        else if(elementFaction == "WATER")
          element = Dragon::WATER;
        else if(elementFaction == "EARTH")
          element = Dragon::EARTH;
        else if(elementFaction == "AIR")
          element = Dragon::AIR;
        else if(elementFaction == "FLESHGORGER")
          faction = Ghoul::FLESHGORGER;
        else if(elementFaction == "SHADOWSTALKER")
          faction = Ghoul::SHADOWSTALKER;
        else if(elementFaction == "PLAGUEWEAVER")
          faction = Ghoul::PLAGUEWEAVER;

        // heads 
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingHeads(temp);
        streamingHeads >> heads;

          // flightTransformSummoning
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingFlight(temp);
        streamingFlight >> flightTransformSummoning;

        // decay
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingDecay(temp);
        streamingDecay >> decay;

        
        // affinities 
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingAffinities(temp);
        while(std::getline(streamingAffinities, affinity, ';')){
            if(affinity == "PSIONIC")
              affinities.push_back(Mindflayer::PSIONIC);
            else if(affinity == "TELEPATHIC")
              affinities.push_back(Mindflayer::TELEPATHIC);
            else if(affinity == "ILLUSIONARY")
              affinities.push_back(Mindflayer::ILLUSIONARY);
        }
        
        //projectiles
        std::getline(streamingSentence, temp, ',');
        std::istringstream streamingProjectiles(temp);
        while(std::getline(streamingProjectiles, projectile, ';')){
            Mindflayer::Projectile enterVector = {};
            std::istringstream streaming(projectile);
            std::getline(streaming, projectileType, '-');
            std::cout << projectileType << std::endl;
            std::getline(streaming, projectileQuantityString);
            std::cout << "Type: " << enterVector.type_ << " Quantity: " << enterVector.quantity_ << std::endl;
            if(projectileType == "PSIONIC" || projectileType == "TELEPATHIC" || projectileType == "ILLUSIONARY"){
              std::istringstream streamingProjectileQuantity(projectileQuantityString);
              streamingProjectileQuantity >> enterVector.quantity_;
              if(projectileType == "PSIONIC")
                enterVector.type_ = Mindflayer::PSIONIC;
              else if(projectileType == "TELEPATHIC")
                enterVector.type_ = Mindflayer::TELEPATHIC;
              else if(projectileType == "ILLUSIONARY")
                enterVector.type_ = Mindflayer::ILLUSIONARY;
              projectiles.push_back(enterVector);
            }
    

        }

        // dynamically allocating creatures
        if(type == "DRAGON"){
          Dragon *dragon = new Dragon(name, category, hitpoints, level, tame, element, heads, flightTransformSummoning);
          enterCavern(dragon);
        }
        else if(type == "GHOUL"){
          Ghoul *ghoul = new Ghoul(name, category, hitpoints, level, tame, decay, faction, flightTransformSummoning);
          enterCavern(ghoul);
        }
        else if(type == "MINDFLAYER"){
          Mindflayer *mindflayer = new Mindflayer(name, category, hitpoints, level, tame, projectiles, flightTransformSummoning, affinities);
          enterCavern(mindflayer);
        }
        projectiles.clear();
        affinities.clear();
      }
      file_name.close(); //close file
    }


 /**
    @post: For every creature in the cavern, displays each creature's information
*/
    void Cavern::displayCreatures() const{
      for(int i = 0; i < item_count_; i ++){
        items_[i]->display();
      }
    }
    
    

/**
    @param: a string reference to a category
    @post: For every creature in the cavern of the given category (only exact matches to the input string), displays each creature's information

*/
    void Cavern::displayCategory(const std::string& category)const{
      for(int i = 0 ; i < item_count_; i++){
        if(items_[i]->getCategory() == category){
          items_[i]->display();
          std::cout << std::endl;
        }
      }
    }
    
  

/**
    @post: Every creature in the cavern eats a MycoMorsel.
*/
    bool Cavern::mycoMorselFeast() const{
      bool eats = true;
      for(int i = 0; i < item_count_ || eats == false; i++){
        if(!(items_[i]->eatMycoMorsel()))
          eats = false;
      }
      return eats;
    }
