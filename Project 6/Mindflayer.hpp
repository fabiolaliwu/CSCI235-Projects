/*
CSCI235 Spring 2024
Project 4 - MycoMorsels
Georgina Woo
Dec 24 2023
Mindflayer.hpp defines the constructors and private and public functions of the Mindflayer class
*/

/*
CSCI235 Spring 2024
Project 6 - Cavern
Fabiola Li Wu
April 5th 2024
Mindflayer.hpp defines the constructors and private and public functions of the Mindflayer class
*/
#ifndef MINDFLAYER_HPP
#define MINDFLAYER_HPP

#include "Creature.hpp"
#include <vector>

class Mindflayer : public Creature
{
public:
    enum Variant
    {
        PSIONIC,
        TELEPATHIC,
        ILLUSIONARY
    };

    struct Projectile
    {
        Variant type_;
        int quantity_;
    };

    Mindflayer();
    Mindflayer(const std::string &name, Category category = ALIEN, int hitpoints = 1, int level = 1, bool tame = false, std::vector<Projectile> projectiles = {}, bool summoning = false, std::vector<Variant> affinities = {});
    std::vector<Projectile> getProjectiles() const;
    void setProjectiles(const std::vector<Projectile> &projectiles);
    bool getSummoning() const;
    void setSummoning(const bool &summoning);
    std::vector<Variant> getAffinities() const;
    void setAffinities(const std::vector<Variant> &affinities);
    std::string variantToString(const Variant &variant) const;
    void display() const override;
    bool eatMycoMorsel() override;

    /**
     * @param: A const reference to int corresponding to the attack to be added to the attack queue.
     * @post: Adds an attack to the attack queue based on the int parameter.
     * Here are the attacks for the Mindflayer:
     *
     * 1: PSIONIC BOLT/TENTACLE SLAP
     *  If the Mindflayer has a PSIONIC projectile:
     *      Attack name: PSIONIC BOLT
     *      If the Mindflayer has a PSIONIC affinity:
     *          Damage: 3 PSIONIC
     *      Else:
     *          Damage: 2 PSIONIC
     * If the Mindflayer does not have a PSIONIC projectile:
     *     Attack name: TENTACLE SLAP
     *     Damage: 1 PHYSICAL, 1 EMOTIONAL
     *
     * 2: TELEPATHIC BOLT/TENTACLE SLAP
     * If the Mindflayer has a TELEPATHIC projectile:
     *      Attack name: TELEPATHIC BOLT
     *      If the Mindflayer has a TELEPATHIC affinity:
     *      Damage: 3 TELEPATHIC
     *      Else:
     *          Damage: 2 TELEPATHIC
     * If the Mindflayer does not have a TELEPATHIC projectile:
     *      Attack name: TENTACLE SLAP
     *      Damage: 1 PHYSICAL, 1 EMOTIONAL
     *
     * 3: ILLUSIONARY BOLT/TENTACLE SLAP
     * If the Mindflayer has an ILLUSIONARY projectile:
     *      Attack name: ILLUSIONARY BOLT
     *      If the Mindflayer has an ILLUSIONARY affinity:
     *          Damage: 3 ILLUSIONARY
     *      Else:
     *          Damage: 2 ILLUSIONARY
     * If the Mindflayer does not have an ILLUSIONARY projectile:
     *      Attack name: TENTACLE SLAP
     *      Damage: 1 PHYSICAL, 1 EMOTIONAL
     *
     */
    bool hasVariant(const std::string &variant);
    void addAttack(const int &attack);

    /**
      @post     : displays the attacks of the Mindflayer in the form:
      [MINDFLAYER] Choose an attack (1-3):\n1: PSIONIC BOLT\t\t2: TELEPATHIC BOLT\t\t3: ILLUSIONARY BOLT\n
    */
    void displayAttacks() const;

private:
    std::vector<Projectile> projectiles_;
    bool summoning_;
    std::vector<Variant> affinities_;
};
#endif // MINDFLAYER_HPP