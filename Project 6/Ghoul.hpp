/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Ghoul.hpp defines the constructors and private and public functions of the Ghoul class
*/

/*
CSCI235 Spring 2024
Project 6 - Cavern
Fabiola Li Wu
April 5th 2024
Ghoul.hpp defines the constructors and private and public functions of the Ghoul class
*/

#ifndef GHOUL_HPP
#define GHOUL_HPP

#include "Creature.hpp"

class Ghoul : public Creature
{
public:
    enum Faction
    {
        NONE,
        FLESHGORGER,
        SHADOWSTALKER,
        PLAGUEWEAVER
    };
    Ghoul();
    Ghoul(const std::string &name, Category category = UNDEAD, int hitpoints = 1, int level = 1, bool tame = false, int decay = 0, Faction faction = NONE, bool transformation = false);

    /**
        Getter for the level of decay.
        @return     : The level of decay (an integer)
    */
    int getDecay() const;

    /**
        Setter for the level of decay.
        @param      : A reference to the level of decay (an integer)
        @pre        : The level of decay must be >= 0 (do nothing otherwise)
        @post       : The level of decay is set to the value of the parameter.
        @return     : true if the level of decay was set, false otherwise
    */
    bool setDecay(const int &decay);

    /**
        Getter for the faction.
        @return     : The faction (a string representation of the Faction enum)
    */
    std::string getFaction() const;

    /**
        Setter for the faction.
        @param      : A reference to the faction (a Faction enum)
        @post       : The faction is set to the value of the parameter.
    */
    void setFaction(const Faction &faction);

    /**
        Getter for the transformation.
        @return     : The transformation (a boolean)
    */
    bool getTransformation() const;

    /**
        Setter for the transformation.
        @param      : A reference to the transformation (a boolean)
        @post       : The transformation is set to the value of the parameter.
    */
    void setTransformation(const bool &transformation);
    void display() const override;
    bool eatMycoMorsel() override;
    /**
     * @param: A const reference to int corresponding to the attack to be added to the attack queue.
     * @post: Adds an attack to the attack queue based on the int parameter.
     * Here are the attacks for the Ghoul:
     *
     * 1: Attack name: BITE
     *   if ALIEN: 4 PHYSICAL
     *   if MYSTICAL:
     *      if FLESHGORGER: 2 PHYSICAL
     *      if SHADOWSTALKER: 2 PHYSICAL, 1 VOID
     *      if PLAGUEWEAVER: 2 PHYSICAL, 1 POISON
     *      if NONE: 2 PHYSICAL
     *  if UNDEAD: 2 PHYSICAL, 1 POISON
     *  if UNKNOWN: 2 PHYSICAL
     *
     * 2:
     *  if FLESHGORGER/NONE:
     *      Attack name: CLAW
     *      2 PHYSICAL
     *  if SHADOWSTALKER:
     *     Attack name: SLASH
     *     2 PHYSICAL, 1 VOID
     * if PLAGUEWEAVER:
     *    Attack name: INFECT
     *    2 PHYSICAL, 1 POISON
     *
     * 3:
     *  if FLESHGORGER/NONE:
     *     Attack name: FLY SWARM
     *     3 PHYSICAL
     * if SHADOWSTALKER:
     *     Attack name: SHROUD OF DARKNESS
     *     2 PHYSICAL, 1 VOID
     * if PLAGUEWEAVER:
     *     Attack name: PLAGUE CLOUD
     *     2 PHYSICAL, 1 POISON
     *
     */
    void addAttack(const int &attack);

    /**
      @post     : displays the attacks of the Ghoul in the form:
      [GHOUL] Choose an attack (1-3):\n1: BITE\t\t2: CLAW\t\t3: CLOUD OF DOOM\n
    */
    void displayAttacks() const;

private:
    int decay_;
    Faction faction_;
    bool transformation_;
};

#endif // GHOUL_HPP