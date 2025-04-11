/*
CSCI235 Spring 2024
Project 2 - Test
Fabiola Li Wu
Feb 22nd 2024
main.cpp will test every function of Pantry :)
*/
#include <iostream>
#include "Pantry.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"

int main()
{
    Pantry pantry("recipes.csv");

    // //pantry.pantryList("NONE");
    // std::vector<Ingredient*> recipe= {};
    // Ingredient *ingredient = new Ingredient("LAST", "First ingredient", 1, 20, recipe);
    // pantry.addIngredient(ingredient);

    // Ingredient *ingredient5 = new Ingredient("5th", "First ingredient", 1, 20, recipe);
    // pantry.addIngredient(ingredient);

    // Ingredient *ingredient6 = new Ingredient("6th", "First ingredient", 4, 20, recipe);
    // pantry.addIngredient(ingredient);

    // Ingredient *ingredient2 = new Ingredient("NAME", "Second ingredient", 1 , 40, {ingredient});
    // pantry.addIngredient(ingredient2);

    // // std::vector<Ingredient*> recipe2;
    // // // {ingredient, ingredient2};
    // // recipe2.push_back(ingredient);
    // // recipe2.push_back(ingredient2);
    // Ingredient *ingredient3 = new Ingredient("BOOL", "Third ingredient", 0, 10, {ingredient2, ingredient});
    // pantry.addIngredient(ingredient3);
    // // pantry.printIngredient(ingredient3);
    // // std::cout << std::endl;

    // Ingredient *ingredient4 = new Ingredient("HELLO", "Fourth ingredient", 0, 9, {ingredient2, ingredient3});
    // pantry.addIngredient(ingredient4);

    // Ingredient *ingredient7 = new Ingredient("WORLD", "Seventh ingredient", 0, 9, {ingredient, ingredient5});
    // pantry.addIngredient(ingredient7);

    // pantry.ingredientQuery("WORLD");

    // std::cout << "\nCan Create 7? " << (pantry.canCreate(ingredient7)? "TRUE": "FALSE") << std::endl;
    // std::cout << " HDHDHDH " <<std::endl;
    // pantry.pantryList("CRAFTABLE");
    //  std::cout << pantry.getPosOf("NAME") << std::endl;
    //  std::cout << (pantry.contains("NAME")? "TRUE":"FALSE") << std::endl;
    //  pantry.printIngredient(ingredient);
    //  pantry.printIngredient(ingredient2);
    //  pantry.printIngredient(ingredient3);
    //  std::cout << std::endl;
    //  std::cout << "\nCan Create 1? " << (pantry.canCreate(ingredient)? "TRUE": "FALSE") << std::endl;
    //  std::cout << "\nCan Create 2? " << (pantry.canCreate(ingredient2)? "TRUE": "FALSE") << std::endl;
    //  std::cout << "\nCan Create 3? " << (pantry.canCreate(ingredient3)? "TRUE": "FALSE") << std::endl;
    //  std::cout << "\nCan Create4? " << (pantry.canCreate(ingredient4)? "TRUE": "FALSE") << std::endl;
    // std::cout << "Pantry Value: " << pantry.calculatePantryValue() << std::endl << std::endl;

    // pantry.ingredientQuery("AST");
    // pantry.ingredientQuery("LAST");
    // pantry.ingredientQuery("NAME");
    // pantry.ingredientQuery("BOOL");
    // pantry.ingredientQuery("HELLO");

    // pantry.ingredientQuery("HELLO");

    // pantry.ingredientQuery("Inferno_Espresso");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("Spectral_Handcuffs");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("Psychic_Kaleidoscope");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("Mystical_Smoothie");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("Ember_Spice");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("inWhispering_Essence6");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("Mystical_Mushroom");
    // std::cout<<std::endl;
    // pantry.ingredientQuery("MycoMorsel");
    // pantry.pantryList("NONE");

    // pantry.ingredientQuery("in1");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in2");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in3");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in4");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in5");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in6");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in7");
    // std::cout << std::endl;
    // pantry.ingredientQuery("in8");

    // std::cout << std::endl;

    pantry.pantryList("NONE");

    return 0;
}