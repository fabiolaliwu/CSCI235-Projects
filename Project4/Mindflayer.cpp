/*
CSCI235 Spring 2024
Project 2 - Derived Classes
Fabiola Li Wu
Feb 9th 2024
Mindflayer.cpp implements the constructors and private and public functions of the Mindflayer class
*/

#include "Mindflayer.hpp"

Mindflayer::Mindflayer() : projectiles_{}, summoning_{false}, affinities_{}
{
    setCategory(ALIEN);
}

Mindflayer::Mindflayer(const std::string& name, Category category, int hitpoints, int level, bool tame, std::vector<Projectile> projectiles, bool summoning, std::vector<Variant> affinities) : Creature(name, category, hitpoints, level, tame)
{
    setProjectiles(projectiles);
    summoning_ = summoning;
    setAffinities(affinities);
}

std::vector<Mindflayer::Projectile> Mindflayer::getProjectiles() const
{
    return projectiles_;
}

void Mindflayer::setProjectiles(const std::vector<Projectile>& projectiles)
{
    std::vector<Projectile> temp;
    for(int i = 0; i < projectiles.size(); i++)
    {
        bool found = false;
        for(int j = 0; j < temp.size(); j++)
        {
            if(projectiles[i].type_ == temp[j].type_)
            {
                if(projectiles[i].quantity_ > 0)
                {
                    temp[j].quantity_ += projectiles[i].quantity_;
                    found = true;
                }
            }
        }
        if(!found)
        {
            if(projectiles[i].quantity_ > 0)
            {
                temp.push_back(projectiles[i]);
            }
        }
    }
    projectiles_ = temp;
}

void Mindflayer::setSummoning(const bool& summoning)
{
    summoning_ = summoning;
}

bool Mindflayer::getSummoning() const
{
    return summoning_;
}

std::vector<Mindflayer::Variant> Mindflayer::getAffinities() const
{
    return affinities_;
}

void Mindflayer::setAffinities(const std::vector<Variant>& affinities)
{
    std::vector<Variant> temp;
    for(int i = 0; i < affinities.size(); i++)
    {
        bool found = false;
        for(int j = 0; j < temp.size(); j++)
        {
            if(affinities[i] == temp[j])
            {
                found = true;
            }
        }
        if(!found)
        {
            temp.push_back(affinities[i]);
        }
    }
    affinities_ = temp;
}

std::string Mindflayer::variantToString(const Variant& variant) const
{
    switch(variant)
    {
        case PSIONIC:
            return "PSIONIC";
        case TELEPATHIC:
            return "TELEPATHIC";
        case ILLUSIONARY:
            return "ILLUSIONARY";
        default:
            return "NONE";
    }
}

 /**
    @post     : displays Mindflayer data in the form:
    "MINDFLAYER - [NAME]\n
    CATEGORY: [CATEGORY]\n
    HP: [HITPOINTS]\n
    LVL: [LEVEL]\n
    TAME: [TRUE/FALSE]\n
    SUMMONING: [SUMMONING]\n
    [PROJECTILE TYPE 1]: [QUANTITY 1]\n
    [PROJECTILE TYPE 2]: [QUANTITY 2]\n
    AFFINITIES: \n
    [AFFINITY 1]\n
    [AFFINITY 2]\n"

    NOTE: For the Projectiles, print out the type and quantity of each projectile in the format: 
    [TYPE]: [QUANTITY] for each projectile in the vector, where the type is the string equivalent of the Variant (eg. "PSIONIC"/"TELEPATHIC"/"ILLUSIONARY"). If there are no projectiles, don't print anything. 

    For the Affinities, print out each affinity in the format: [AFFINITY 1]\n[AFFINITY 2]\n for each Affinity in the vector, where the Affinity is the string equivalent of the Variant (eg. "PSIONIC"/"TELEPATHIC"/"ILLUSIONARY"). If there are no affinities, don't print anything, including the label "AFFINITIES:". 
    
    Example:
    MINDFLAYER - JHOCTOPUS
    CATEGORY: UNDEAD
    HP: 3
    LVL: 6
    TAME: TRUE
    SUMMONING: TRUE
    PSIONIC: 2
    TELEPATHIC: 11
    AFFINITIES: 
    PSIONIC
    ILLUSIONARY

*/
    void Mindflayer::display(){
        std::cout << "MINDFLAYER - " << getName() << std::endl
                << "CATEGORY: " << getCategory() << std::endl
                << "HP: " << getHitpoints() << std::endl
                << "LVL: " << getLevel() << std::endl
                << "TAME: " << (isTame() ? "TRUE" : "FALSE") << std::endl
                << "SUMMONING: " << (getSummoning()? "TRUE" : "FALSE") << std::endl;
    //prints projectiles
        if(projectiles_.size() > 0){
            for(int i = 0; i < projectiles_.size(); i++){
                std::cout<< variantToString(projectiles_[i].type_) << ": ";
                std::cout << projectiles_[i].quantity_ << std::endl;
            }
        }

    // prints affinities
        if(affinities_.size() > 0){
            std::cout << "AFFINITIES: " << std::endl;
            if(affinities_.size() > 0){
                for(int i = 0; i < affinities_.size(); i++)
                    std::cout<< variantToString(affinities_[i]) << std::endl;
            }
        }      
    }

    /**
    @post: 
    If the creature is UNDEAD, it becomes tame if not already, as it appreciates the gesture, even though as an UNDEAD it does not 
    really eat. It gains 1 hitpoint from the mysterious powers it receives by wearing the mushroom as a hat. Nothing else happens.

    If the creature is MYSTICAL, if it can summon a Thoughtspawn, it gives the mushroom to the Thoughtspawn instead. If it cannot 
    summon a Thoughtspawn and is tame, it eats the mushroom to be polite. If it only had 1 hitpoint left, it remains at 1 hitpoint 
    and becomes untame, else it loses 1 hitpoint. If it cannot summon a Thoughtspawn and is untame, it decides it doesn't have to 
    deal with this and it leaves the Cavern. Nothing else happens.

    If the creature is an ALIEN, if it has Telepathic affinity, it convinces Selfa Ensert to eat the mushroom instead, and gains 1 
    hitpoint from laughing at their resulting illness (as laughter is the best medicine).

    If it is an ALIEN and does not have Telepathic affinity, but has a Telepathic projectile, it uses one of such projectile to 
    achieve the same effect. (Remember to remove the projectile from the vector if it only had 1 left)

    If it is an ALIEN and does not have Telepathic affinity or a Telepathic projectile, it eats the mushroom and gains 2 hitpoints.
    As it turns out, the mushroom was good for it. It becomes tame if it was not already. Nothing else happens.

    @return   : true if the creature leaves the Cavern, false otherwise
*/
bool Mindflayer::eatMycoMorsel(){
    bool leaves = false;
    if(getCategory() == "UNDEAD"){
        setTame(true);
        setHitpoints(getHitpoints() + 1);
    }
    else if(getCategory() == "MYSTICAL"){
        if(!summoning_){
            if(isTame()){ 
                if(getHitpoints() == 1)
                    setTame(false);
                else if(getHitpoints() > 1)
                    setHitpoints(getHitpoints() - 1);
            }
            else
                leaves = true;
        }
    } 
    else if(getCategory() == "ALIEN"){
        // checks if it has TELEPATHIC in Affinity 
        bool hasTelepathicInAffinity = false;
        if(affinities_.size() > 0){
            for(int i = 0; (i < affinities_.size()) && (!hasTelepathicInAffinity); i++){
                if(affinities_[i] == 1)
                    hasTelepathicInAffinity = true;
            }
        }
        
        // checks if it has TELEPATHIC in Projectiles
        bool hasTelepathicInProjectiles = false;
        // if so, then put the index here
        int indexOfTelepathicInProjectiles = -1;
        if(projectiles_.size() > 0){
            for(int i = 0; (i < projectiles_.size()) && (!hasTelepathicInProjectiles); i++){
                if(projectiles_[i].type_ == 1){
                    hasTelepathicInProjectiles = true;
                    indexOfTelepathicInProjectiles = i;
                }
            }
        }

        // has Telepathic affinity, gains 1 hitpoint
        if(hasTelepathicInAffinity)
            setHitpoints(getHitpoints() + 1);
        // does not have Telepathic affinity
        else if(!hasTelepathicInAffinity ){
            // has a Telepathic projectile, it uses one of such projectile to achieve the same effect
            // (Remember to remove the projectile from the vector if it only had 1 left)
            if(hasTelepathicInProjectiles){
                if(projectiles_[indexOfTelepathicInProjectiles].quantity_ == 1)
                    projectiles_.erase(projectiles_.begin() + indexOfTelepathicInProjectiles);
                else
                    projectiles_[indexOfTelepathicInProjectiles].quantity_ -= 1;
                setHitpoints(getHitpoints() + 1);
            }
            // does not have Telepathic projectile, gains 2 hitpoint and tame if it was not already
            else{
                setHitpoints(getHitpoints() + 2);
                setTame(true);
            }
        }
    }
    return leaves;
}
