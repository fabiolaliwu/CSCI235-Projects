/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Dragon.hpp defines the constructors and private and public functions of the Dragon class
*/

/*
CSCI235 Spring 2024
Project 6 - Cavern
Fabiola Li Wu
April 5th 2024
Dragon.hpp defines the constructors and private and public functions of the Dragon class
*/
#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "Creature.hpp"

class Dragon : public Creature
{
public:
    enum Element
    {
        NONE,
        FIRE,
        WATER,
        EARTH,
        AIR
    };
    Dragon();
    Dragon(const std::string &name, Category category = MYSTICAL, int hitpoints = 1, int level = 1, bool tame = false, Element element = NONE, int number_of_heads = 1, bool flight = false);
    std::string getElement() const;
    void setElement(const Element &element);
    int getNumberOfHeads() const;
    bool setNumberOfHeads(const int &number_of_heads);
    bool getFlight() const;
    void setFlight(const bool &flight);
    void display() const override;
    bool eatMycoMorsel() override;
    /**
* @param: A const reference to int corresponding to the attack to be added to the attack queue.
* @post: Adds an attack to the attack queue based on the int parameter.
* Here are the attacks for the Dragon:

* 1: Attack name: BITE
*      if ALIEN: 4 PHYSICAL
*      if MYSTICAL: 2 PHYSICAL, and additional damage of 1 [FIRE/WATER/EARTH/AIR] if the Dragon has an elemental affinity of FIRE, WATER, EARTH, or AIR)
*      if UNDEAD: 2 PHYSICAL, 1 POISON
*      if UNKNOWN: 2 PHYSICAL

* 2: Attack name: STOMP
*      if ALIEN: 2 PHYSICAL
*      if MYSTICAL: 1 PHYSICAL, and additional damage of 1 [FIRE/WATER/EARTH/AIR] if the Dragon has an elemental affinity of FIRE, WATER, EARTH, or AIR)
*      if UNDEAD: 1 PHYSICAL, 1 POISON
*      if UNKNOWN: 1 PHYSICAL

* 3: Attack name: [ELEMENTAL BREATH/BAD BREATH], where the name is ELEMENTAL BREATH if the Dragon has an elemental affinity, otherwise it is BAD BREATH
*      if ALIEN: 6 [POISON/FIRE/WATER/EARTH/AIR], where the damage type is the Dragon's elemental affinity if it has one, otherwise it is POISON
*      if MYSTICAL: 3 [POISON/FIRE/WATER/EARTH/AIR], where the damage type is the Dragon's elemental affinity if it has one, otherwise it is POISON
*      if UNDEAD: 3 [POISON/FIRE/WATER/EARTH/AIR], 1 POISON. The damage types and amount are added to the vector as two separate entries, even if both entries are POISON type.
*      if UNKNOWN: 3 [POISON/FIRE/WATER/EARTH/AIR] where the damage type is the Dragon's elemental affinity if it has one, otherwise it is POISON
*/
    void addAttack(const int &attack);

    /**
     * @post: Displays available attacks and promps the user to enter 2 numbers in the range [1,3]
     *        Print in the following form:
     *        [DRAGON] Choose an attack (1-3):\n1: BITE\t\t2: STOMP\t\t3: ELEMENTAL BREATH\n
     */
    void displayAttacks() const;

private:
    Element element_;
    int number_of_heads_;
    bool flight_;
};

#endif // DRAGON_HPP