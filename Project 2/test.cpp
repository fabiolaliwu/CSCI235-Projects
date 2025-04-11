/*
CSCI235 Spring 2024
Project 2 - Test
Fabiola Li Wu
Feb 9th 2024
test.cpp will test every class
*/
#include "Creature.hpp"
#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"
#include <iostream>
#include <cctype>

// displays Dragon information
void displayDragon(Dragon dragon){
    std::cout << "NAME: " << dragon.getName() << endl
            << "CATEGORY: " << dragon.getCategory() << endl
            << "HP: " << dragon.getHitpoints() << endl
            << "LVL: " << dragon.getLevel() << endl
            << "TAME: ";
    if(dragon.isTame() == 1)
        std::cout << "TRUE";
    else
        std::cout << "FALSE";
        std::cout << endl;
    //dragon.display();
    cout << "ELEMENT: " << dragon.getElement() << endl;
    cout << "HEADS: " << dragon.getNumberOfHeads() << endl;
    cout << "FLIGHT: ";
    if(dragon.getFlight() == 1)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl << endl;
}

// display Ghoul information
void displayGhoul( Ghoul ghoul){
    cout << "NAME: " << ghoul.getName() << endl;
    cout << "CATEGORY: " << ghoul.getCategory() << endl;
    cout << "HP: " << ghoul.getHitpoints() << endl;
    cout << "LVL: " << ghoul.getLevel() << endl;
    cout << "TAME: ";
    if(ghoul.isTame() == 1)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    //ghoul.display();
    cout << "DECAY: " << ghoul.getDecay() << endl;
    cout << "FACTION: " << ghoul.getFaction() << endl;
    cout << "TRANSFORM: ";
    if(ghoul.getTransformation() == 1)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl << endl;
}

// display Mindflayer information
void displayMindflayer(Mindflayer mindflayer){
    cout << "NAME: " << mindflayer.getName() << endl;
    cout << "CATEGORY: " << mindflayer.getCategory() << endl;
    cout << "HP: " << mindflayer.getHitpoints() << endl;
    cout << "LVL: " << mindflayer.getLevel() << endl;
    cout << "TAME: ";
    if(mindflayer.isTame() == 1)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl << "SUMMONING: ";
    if(mindflayer.getSummoning() == 1)
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;
    
    // prints out projectiles
    vector <Mindflayer::Projectile> projectiles = mindflayer.getProjectiles();
    if(projectiles.size() > 0){
        for(int i = 0; i < projectiles.size(); i++){
            cout<< mindflayer.variantToString(projectiles[i].type_) << ": ";
            cout << projectiles[i].quantity_ << endl;
        }
    }
    
    // prints affinities
    vector <Mindflayer::Variant> affinities = mindflayer.getAffinities();
    if(affinities.size() > 0){
        cout << "AFFINITIES:" << endl;
        if(affinities.size() > 0){
            for(int i = 0; i < affinities.size(); i++)
                cout<< mindflayer.variantToString(affinities[i]) << endl;
        }
    }
    cout << endl;
}

// main test driver
int main(){
    //    2.1.1 Instantiate a default Dragon
    //    - Print out the information for the default Dragon based on the format above
    Dragon dragon;
    displayDragon(dragon);
    
    //    2.1.2 Instantiate a Dragon with the parameterized constructor with the following creature details:
    //    Name: Smog
    Dragon dragon3("Smog");
    displayDragon(dragon3);
    
    //    2.1.3 Instantiate a Dragon with the parameterized constructor with the following creature details:
    //    Name: BURNY
    //    Category: UNDEAD
    //    Hitpoints: 100
    //    Level: 10
    //    Tame: True
    //    Element: FIRE
    //    Number of heads: 1
    //    Flight: True
    //string name_burny = "BURNY";
    Dragon dragon4("BURNY", Creature::UNDEAD, 100,10, true, Dragon::FIRE, 1, true);
    displayDragon(dragon4);
    
    //    2.1.4 Make the following changes to Burny using the appropriate setter functions:
    //    - Set the element to WATER
    //    - Set the number of heads to 2
    //    - Set the number of heads to 0
    //    - Set the flight flag to False
    //
    //    - Print out the information for Burny based on the format above
    dragon4.setElement(Dragon::WATER);
    //const int HEADS = 2;
    dragon4.setNumberOfHeads(2);
    //const int HEADS1 = 0;
    dragon4.setNumberOfHeads(0);
    dragon4.setFlight(false);
    displayDragon(dragon4);
    
    
    
    //    2.2.1 Instantiate a default Ghoul
    //    - Print out the information for the default Ghoul based on the format above
    Ghoul ghoul;
    displayGhoul(ghoul);
    
    //    2.2.2 Instantiate a Ghoul with the parameterized constructor with the following creature details:
    //    Name: Homph
    //
    //    - Print out the information for Homph based on the format above
    //string ghoul_name = "Homph";
    Ghoul ghoul1("Homph");
    displayGhoul(ghoul1);
    
    //    2.2.3 Instantiate a Ghoul with the parameterized constructor with the following creature details:
    //Name: CHOMPER
    //Category: ALIEN
    //Hitpoints: 100
    //Level: 10
    //Tame: True
    //Decay: 3
    //Faction: FLESHGORGER
    //Transform: True
    //string ghoul_name2 = "CHOMPER";
    Ghoul ghoul2("CHOMPER", Creature::ALIEN, 100, 10, true, 3, Ghoul::FLESHGORGER, true);
    displayGhoul(ghoul2);
    
    //    2.2.4 Make the following changes to Chomper using the appropriate setter functions:
    //    - Set the decay to 2
    //    - Set the decay to -20
    //    - Set the faction to SHADOWSTALKER
    //    - Set the transformation flag to False
    ghoul2.setDecay(2);
    ghoul2.setDecay(-20);
    ghoul2.setFaction(Ghoul::SHADOWSTALKER);
    ghoul2.setTransformation(false);
    displayGhoul(ghoul2);
    
    
    //    2.3.1 Instantiate a default Mindflayer
    //    - Print out the information for the default Mindflayer based on the format above
    Mindflayer mindflayer;
    displayMindflayer(mindflayer);
    
    //    2.3.2 Instantiate a Mindflayer with the parameterized constructor with the following creature details:
    //    Name: BIGBRAIN
    //    Category: MYSTICAL
    //    Hitpoints: 100
    //    Level: 10
    //    Tame: True
    //    Projectiles: {{PSIONIC, 2}, {TELEPATHIC, 1}, {PSIONIC, 1}, {ILLUSIONARY, 3}}
    //    Summoning: True
    //    Affinities: {PSIONIC, TELEPATHIC, PSIONIC, ILLUSIONARY}
    //
    //    - Print out the information for Bigbrain based on the format above
    //string name4 = "";
    Mindflayer mindflayer2("BIGBRAIN", Creature::MYSTICAL, 100, 10, true, {{Mindflayer::PSIONIC, 2}, {Mindflayer::TELEPATHIC, 1}, {Mindflayer::PSIONIC, 1}, {Mindflayer::ILLUSIONARY, 3}}, true, {Mindflayer::PSIONIC, Mindflayer::TELEPATHIC, Mindflayer::PSIONIC, Mindflayer::ILLUSIONARY});
    displayMindflayer(mindflayer2);
    return 0;
}
