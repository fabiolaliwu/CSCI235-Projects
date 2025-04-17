/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Cavern.hpp declares the Cavern class along with its private and public members
*/

/*
CSCI235 Spring 2024
Project 6 - Cavern
Fabiola Li Wu
April 5th 2024
Cavern.hpp declares the Cavern class along with its private and public members
*/
#ifndef CAVERN_HPP
#define CAVERN_HPP

#include "ArrayBag.hpp"
#include "Creature.hpp"
#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"
#include <stack>
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

class Cavern : public ArrayBag<Creature *>
{
public:
  Cavern();
  Cavern(const std::string &filename);
  bool enterCavern(Creature *new_creature);
  bool exitCavern(Creature *creature_to_remove);
  int getLevelSum() const;
  int calculateAvgLevel() const;
  int getTameCount() const;
  double calculateTamePercentage() const;
  int tallyCategory(const std::string &category) const;
  int releaseCreaturesBelowLevel(int level = 0);
  int releaseCreaturesOfCategory(std::string category = "ALL");
  void cavernReport() const;
  void displayCreatures() const;
  void displayCategory(const std::string &category) const;
  void mycoMorselFeast();
  /**
  * @post: Stores the ALIEN Creatures of highest level in the cavern's mystical stack, in the order in which they appear in the Cavern (i.e., starting from index 0 in items_, thus, if the highest level is 5 and there are 3 ALIEN creatures with level 5, the one with lowest index in items_ is at the bottom of the stack and the one with highest index in item_ is at the top of the stack, with a total of 3 ALIEN Creatures on the stack)

  *      : Empty the stack before beginning.
  */
  void initializeAlienStack();

  /**
    * @post: Stores the UNDEAD Creatures of highest level in the cavern's mystical stack, in the order in which they appear in the Cavern (i.e., starting from index 0 in items_, thus, if the highest level is 5 and there are 3 UNDEAD creatures with level 5, the one with lowest index in items_ is at the bottom of the stack and the one with highest index in item_ is at the top of the stack, with a total of 3 UNDEAD Creatures on the stack)
          : Empty the stack before beginning.
    */
  void initializeUndeadStack();

  /**
   * @post: Stores the MYSTICAL Creatures of highest level in the cavern's mystical stack, in the order in which they appear in the Cavern (i.e., starting from index 0 in items_, thus, if the highest level is 5 and there are 3 MYSTICAL creatures with level 5, the one with lowest index in items_ is at the bottom of the stack and the one with highest index in item_ is at the top of the stack, with a total of 3 MYSTICAL Creatures on the stack)
   *      : Empty the stack before beginning.
   */
  void initializeMysticalStack();

  /**
   * @post: Stores the UNKNOWN Creatures of highest level in the cavern's mystical stack, in the order in which they appear in the Cavern (i.e., starting from index 0 in items_, thus, if the highest level is 5 and there are 3 UNKNOWN creatures with level 5, the one with lowest index in items_ is at the bottom of the stack and the one with highest index in item_ is at the top of the stack, with a total of 3 UNKNOWN Creatures on the stack)
   *      : Empty the stack before beginning.
   */
  void initializeUnknownStack();

  /**
   * @return: A copy of the stack of highest level Aliens in the cavern
   */
  std::stack<Creature *> getAlienStack() const;

  /**
   * @return: A copy of the stack of highest level Undeads in the cavern
   */
  std::stack<Creature *> getUndeadStack() const;

  /**
   * @return: A copy of the stack of highest level Mysticals in the cavern
   */
  std::stack<Creature *> getMysticalStack() const;

  /**
   * @return: A copy of the stack of highest level Unknowns in the cavern
   */
  std::stack<Creature *> getUnknownStack() const;

  /**
   * @post: clears the stack of highest level Aliens in the cavern
   */
  void clearAlienStack();

  /**
   * @post: clears the stack of highest level Undeads in the cavern
   */
  void clearUndeadStack();

  /**
   * @post: clears the stack of highest level Mysticals in the cavern
   */
  void clearMysticalStack();

  /**
   * @post: clears the stack of highest level Unknowns in the cavern
   */
  void clearUnknownStack();

  /**
   * @param: A stack of creature pointers
   * @pre:   All the creature on the input stack are of same category and same (highest) level
   * @post:  For each creature in the stack, rebuild the Cavern's appropriate stack. (For example, if the creatures given are of category ALIEN, this function should build the Cavern's Alien stack.)
   *        Clear the Cavern's stack of the given category before adding the creatures to the stack.
   *        Before adding each creature to the Cavern's stack, prompt the user to select 2 attacks for the creature.
   *        Preserve the order of the creatures in the stack given. (E.g. The creature at the top of the given stack should also become the creature at the top of the Cavern's stack)
   *        If the input is invalid (valid inputs will be 1,2 or 3 only), keep prompting for a non-negative number that is within range, by printing "INVALID INPUT. TRY AGAIN.\n" and prompt for input again.
   *        When a valid action is read, it is passed to the creature's addAttack function to add the corresponding attack to the creature's attack queue.
   *        Prompting for attacks should be done in the following form (hint: use the creature's displayAttacks function):
   *        SELECT 2 ATTACKS FOR [CREATURE NAME] (1-3):
   *        1: [ATTACK 1 NAME]\t\t2: [ATTACK 2 NAME]\t\t3: [ATTACK 3 NAME]
   */
  void setAttacks(std::stack<Creature *> creature);

private:
  int level_sum_;  // sum of all the levels of the creatures in the cavern
  int tame_count_; // number of tame creatures in the cavern

  // - A stack of pointers to the highest level ALIEN Creatures in the Cavern
  std::stack<Creature *> alien_stack_;
  // - A stack of pointers to the highest level UNDEAD Creatures in the Cavern
  std::stack<Creature *> undead_stack_;
  // - A stack of pointers to the highest level MYSTICAL Creatures in the Cavern
  std::stack<Creature *> mystical_stack_;
  // - A stack of pointers to the highest level UNKNOWN Creatures in the Cavern
  std::stack<Creature *> unknown_stack_;
};
#endif
