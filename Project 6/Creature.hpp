/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Creature.hpp declares the Creature class along with its private and public members
*/
/*
CSCI235 Spring 2024
Project 6 - Cavern
Fabiola Li Wu
April 5th 2024
Creature.hpp declares the Creature class along with its private and public members
*/
#ifndef CREATURE_HPP_
#define CREATURE_HPP_
#include <iostream>
#include <string>
#include <cctype>
#include <queue>

struct Attack
{
    std::string name_;
    std::vector<std::string> type_;
    std::vector<int> damage_;
};

class Creature
{
public:
    enum Category
    {
        UNKNOWN,
        UNDEAD,
        MYSTICAL,
        ALIEN
    };
    Creature();
    Creature(const std::string &name, Category category = UNKNOWN, int hitpoints = 1, int level = 1, bool tame = false);
    bool setName(const std::string &name);
    std::string getName() const;
    void setCategory(const Category &category);
    std::string getCategory() const;
    bool setHitpoints(const int &hitpoints);
    int getHitpoints() const;
    bool setLevel(const int &level);
    int getLevel() const;
    void setTame(const bool &tame);
    bool isTame() const;
    virtual void display() const = 0;
    bool operator==(const Creature &rhs) const;
    bool operator!=(const Creature &rhs) const;
    virtual bool eatMycoMorsel() = 0;
    /**
     * @return a copy of the attackQueue
     */
    std::queue<Attack> getAttackQueue() const;

    /**
     * @param: A const reference to int indicating the attack to be added to the queue.
     * Pure virtual function to be implemented by the derived classes
     */
    virtual void addAttack(const int &attack) = 0;

    /**
     * @param: A const reference to attack to be added to the queue.
     * @post: The attack is added to the queue
     */
    void addAttack(const Attack &attack);

    /**
     * @post: the attackQueue is emptied
     */
    void clearAttackQueue();

    /**
     * @post: Displays the options for the attacks
     * Pure virtual function to be implemented by the derived classes
     */
    virtual void displayAttacks() const = 0;

private:
    std::string name_;
    Category category_;
    int hitpoints_;
    int level_;
    bool tame_;
    // An attack queue to store the creature's attacks
    std::queue<Attack> attack_queue_;
};

#endif