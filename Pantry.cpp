/*
CSCI235 Spring 2024
Project 5 - Pantry
Fabiola Li Wu
Feb 22nd 2024
Pantry.cpp declares the Pantry class along with its private and public members
*/
#include "Pantry.hpp"

/**
Default Constructor
*/
Pantry::Pantry()
{
}

/**
@param: the name of an input file
@pre: Formatting of the csv file is as follows:
Name: A string
Description: A string
Quantity: A non negative integer
Price: A non negative integer
Recipe: A list of Ingredient titles of the form [NAME1] [NAME2];
For example, to make this ingredient, you need (Ingredient 1 AND Ingredient 2)
The value may be NONE.
Notes:
- The first line of the input file is a header and should be ignored.
- The recipe are separated by a semicolon and may be NONE.
- The recipe may be in any order.
- If any of the recipe are not in the list, they should be created as new ingredients with the following information:
    - Title: The name of the ingredient
    - Description: "UNKNOWN"
    - Quantity: 0
    - Recipe: An empty vector
- However, if you eventually encounter a ingredient that matches one of the "UNKNOWN" ingredients while parsing the file,
you should update all the ingredient details.

For example, given a row in the file:
Inferno_Espresso,An energizing elixir brewed with mystical flames providing resistance to caffeine crashes for a limited time.,1,50,Fiery_Bean Ember_Spice

The order of the ingredients in the list:
Fiery_Bean, Ember_Spice, Inferno_Espresso
Hint: update as needed using addIngredient()

@post: Each line of the input file corresponds to a ingredient to be added to the list. No duplicates are allowed.
Hint: use std::ifstream and getline()
*/
Pantry::Pantry(const std::string &fileName)
{
    // open file
    std::ifstream file(fileName);
    if (file.fail())
        exit(1);
    std::string sentence, holder, name, description, recipeIngredients;
    int quantity, price;

    // testing
    std::vector<Ingredient *> recipe = {};

    // get the first line and get rid of it
    std::getline(file, sentence);
    while (std::getline(file, sentence))
    {
        std::istringstream streamingSentence(sentence);
        std::getline(streamingSentence, name, ',');
        std::getline(streamingSentence, description, ',');
        std::getline(streamingSentence, holder, ',');
        quantity = std::stoi(holder);
        std::getline(streamingSentence, holder, ',');
        price = std::stoi(holder);
        std::getline(streamingSentence, holder, ';');
        std::istringstream streamingRecipe(holder);
        while (streamingRecipe >> recipeIngredients)
        {
            // If any of the recipe are not in the list, they should be created as new ingredients
            if (recipeIngredients != "NONE")
            {
                if (!contains(recipeIngredients))
                {
                    Ingredient *ingredient = new Ingredient(recipeIngredients, "UNKNOWN", 0, 0, {});
                    addIngredient(ingredient);
                    recipe.push_back(ingredient);
                }

                // if it is already in the ingredients, just push back
                else if (contains(recipeIngredients))
                {
                    recipe.push_back(getNodeAt(getPosOf(recipeIngredients))->getItem());
                }
            }
        }
        // if you eventually encounter a ingredient that matches one of the "UNKNOWN" ingredients while parsing the file,
        // you should update all the ingredient details.
        if (contains(name))
        {
            Node<Ingredient *> *cur_ptr = getHeadNode();
            while ((cur_ptr != nullptr))
            {
                if (cur_ptr->getItem()->name_ == name && cur_ptr->getItem()->description_ == "UNKNOWN")
                {
                    Ingredient *insertIngredient = new Ingredient(name, description, quantity, price, recipe);
                    cur_ptr->setItem(insertIngredient);
                }
                cur_ptr = cur_ptr->getNext();
            }
        }
        // dynamically creates a new ingredient and then add it to the pantry
        Ingredient *ingredient2 = new Ingredient(name, description, quantity, price, recipe);
        addIngredient(ingredient2);

        // clears the recipe so it does not accumulate in the vector
        recipe.clear();
    }
    file.close();
}

/**
Destructor
@post: Explicitly deletes every dynamically allocated Ingredient object
*/
Pantry::~Pantry()
{
    Node<Ingredient *> *nodeToDelete = head_ptr_;
    while (head_ptr_ != nullptr)
    {
        head_ptr_ = head_ptr_->getNext();
        nodeToDelete->setNext(nullptr);
        delete nodeToDelete;
        nodeToDelete = head_ptr_;
    }
    item_count_ = 0;
}

/**
@param: A const string reference to a ingredient name
@return: The integer position of the given ingredient if it is in the Pantry, -1 if not found.
*/
int Pantry::getPosOf(const std::string &name) const
{
    int counter = 0;
    Node<Ingredient *> *cur_ptr = getHeadNode();
    while ((cur_ptr != nullptr))
    {
        if (cur_ptr->getItem()->name_ == name)
            return counter;
        counter++;
        cur_ptr = cur_ptr->getNext();
    }
    return -1;
}

/**
@param: A const string reference to a ingredient name
@return: True if the ingredient information is already in the Pantry
*/
bool Pantry::contains(const std::string &name) const
{
    if (getPosOf(name) >= 0)
        return true;
    return false;
}

/**
@param:  A pointer to an Ingredient object
@post:  Inserts the given ingredient pointer into the Pantry, unless an ingredient of the same name is already in the pantry.
    Each of its Ingredients in its recipe are also added to the Pantry IF not already in the list.
@return: True if the ingredient was added successfully, false otherwise.
*/
bool Pantry::addIngredient(Ingredient *object)
{
    if (contains(object->name_))
        return false;
    insert(item_count_, object);
    return true;
}

/**
@param: A const string reference representing a ingredient name
@param: A const string reference representing ingredient description
@param: A const int reference representing the ingredient's quantity
@param: A const int reference representing the ingredient's price
@param: A const reference to a vector holding Ingredient pointers representing the ingredient's recipe
@post:   Creates a new Ingredient object and inserts a pointer to it into the Pantry.
    Each of its Ingredients in its recipe are also added to the Pantry IF not already in the list.
@return: True if the ingredient was added successfully
*/
bool Pantry::addIngredient(const std::string &name, const std::string &description, const int &quantity,
                           const int &price, const std::vector<Ingredient *> recipe)
{
    Ingredient *newIngredient = new Ingredient(name, description, quantity, price, recipe);
    if (contains(name))
        return false;
    return addIngredient(newIngredient);
}

/**
@param:  A Ingredient pointer
@return: A boolean indicating if all the given ingredient can be created (all of the ingredients in its recipe can be created,
or if you have enough of each ingredient in its recipe to create it)
*/
bool Pantry::canCreate(Ingredient *ingredient) const
{
    bool craftable = true;
    // see if the ingredients of the recipe of the object are in the INGREDIENTS and can be created
    if (ingredient->recipe_.size() > 0)
    {
        for (int i = 0; i < ingredient->recipe_.size() && craftable; i++)
        {
            if ((ingredient->recipe_[i]->quantity_ > 0) && (!canCreate(ingredient->recipe_[i])))
            {
            }
            else if ((!contains(ingredient->recipe_[i]->name_)) || ((ingredient->recipe_[i]->quantity_ <= 0) && (!canCreate(ingredient->recipe_[i]))))
                return false;
        }
    }
    else if (ingredient->recipe_.size() <= 0)
        return false;
    return true;
}

/**
@param: A Ingredient pointer
@post: Prints the ingredient name, quantity, and description.
The output should be of the form:
[Ingredient Name]: [Quantity]\n
[Ingredient Description]\n
Price: [Price]\n
Recipe:\n
[Ingredient0] [Ingredient1]\n


If the ingredient has no recipe, print "Recipe:\nNONE\n\n" after the price.
*/
void Pantry::printIngredient(Ingredient *ingredient) const
{
    std::cout << ingredient->name_ << ": " << ingredient->quantity_ << std::endl
              << ingredient->description_ << std::endl
              << "Price: " << ingredient->price_ << std::endl
              << "Recipe:" << std::endl;
    if (ingredient->recipe_.size() <= 0)
        std::cout << "NONE" << std::endl
                  << std::endl;
    else
    {
        for (int i = 0; i < ingredient->recipe_.size(); i++)
            std::cout << ingredient->recipe_[i]->name_ << " ";
        std::cout << std::endl
                  << std::endl;
    }
}

/**
@param: A const string reference to a ingredient name
@post:  Prints a list of ingredients that must be created before the given ingredient can be created (missing ingredients for its recipe,
        where you have 0 of the needed ingredient).
    vv If the ingredient is already in the pantry, print "In the pantry([quantity])\n"
    If there are no instances of the ingredient, if it cannot be crafted because of insufficient ingredients,
    print "[Ingredient Name](0)\nMISSING INGREDIENTS"
    If it can be crafted, recursively print the ingredients that need to be used (if there are instances of them) or
    created (if there are no instances of them) in the order that the ingredients appear in the recipe, joined by "<-".
    If the ingredient has no recipe, print "UNCRAFTABLE\n" at the end of the function.

    Below are some of the expected forms. "Scenario: [scenario] is not part of the output. It is just to help you understand
    the expected output.":

    Scenario: The Ingredient does not exist in the list
    Query: [Ingredient Name]
    No such ingredient

    Scenario: The Ingredient exists in the list, and there are >0 instances of it
    Query: [Ingredient Name]
    In the pantry ([Quantity])

            Scenario:   The Ingredient exists in the list, and there are 0 instances of it, and it is craftable by using an
                        ingredient that is already in the pantry
            Query: [Ingredient Name0]
            [Ingredient Name0](C)
            [Ingredient Name1](1)

            Scenario:   The Ingredient exists in the list, and there are 0 instances of it, and it is craftable by using an
                        ingredient that has to be crafted
            Query: [Ingredient Name0]
            [Ingredient Name0](C)
            [Ingredient Name1](C) <- [Ingredient Name2](3)

            Scenario:   The Ingredient exists in the list, and there are 0 instances of it, and there are multiple
                        ingredients that have to be crafted (each row represents a different ingredient inå the original recipe)
            Query: [Ingredient Name0]
            [Ingredient Name0](C)
            [Ingredient Name1](C) <- [Ingredient Name2](3)
            [Ingredient Name3](C) <- [Ingredient Name4](C) <- [Ingredient Name5] (3)

    vv Scenario:   The Ingredient exists in the list, and there are 0 instances of it,
                and it is not craftable (it has no recipe)
    Query: [Ingredient Name0]
    UNCRAFTABLE

            Scenario:   The Ingredient exists in the list, and there are 0 instances of it, and it has a recipe,
                        but you do not have enough of the ingredients to craft it
            Query: [Ingredient Name0]
            [Ingredient Name0](0)
            MISSING INGREDIENTS

HINT: Use canCreate() to determine if the ingredient can be created.
*/

void Pantry::recursivelyPrint(Ingredient *ingredient) const
{
    for (int i = 0; i < ingredient->recipe_.size(); i++)
    {
        std::cout << ingredient->recipe_[i]->name_;
        if (canCreate(ingredient->recipe_[i]))
        {
            std::cout << "(C) <- ";
            recursivelyPrint(ingredient->recipe_[i]);
        }
        else
            std::cout << "(" << ingredient->recipe_[i]->quantity_ << ")\n";
    }
}

void Pantry::ingredientQuery(const std::string &name) const
{
    std::cout << "Query: " << name << std::endl;

    // it is in the list
    if (contains(name))
    {
        // get the ingredient
        Ingredient *targetIngredient;
        targetIngredient = getNodeAt(getPosOf(name))->getItem();

        // Ingredient in the list, and > 0 instances
        if (targetIngredient->quantity_ > 0)
        {
            std::cout << "In the pantry (" << targetIngredient->quantity_ << ")\n";
            if (targetIngredient->recipe_.size() <= 0)
                std::cout << "UNCRAFTABLE" << std::endl;
        }
        else if (targetIngredient->quantity_ == 0)
        {
            // not craftable (it has no recipe)
            if (targetIngredient->recipe_.size() <= 0)
                std::cout << "UNCRAFTABLE" << std::endl;
            // has a recipe, not have enough of the ingredients
            else if ((targetIngredient->recipe_.size() > 0) && (!canCreate(targetIngredient)))
            {
                std::cout << targetIngredient->name_ << "(" << targetIngredient->quantity_ << ")\n";
                std::cout << "MISSING INGREDIENTS" << std::endl;
            }
            // craftable by using an ingredient
            else if (canCreate(targetIngredient))
            {
                std::cout << targetIngredient->name_ << "(C)\n";
                recursivelyPrint(targetIngredient);
            }
        }
    }
    // else if the ingredient is not in the pantry
    else
        std::cout << "No such ingredient\n\n";
}

/**
@return: An integer sum of the price of all the ingredients currently in the list.
Note: This should only include price values from ingredients that you have 1 or more of. Do not consider ingredients that you have 0 of, even if you have the ingredients to make them.
*/
int Pantry::calculatePantryValue() const
{
    int price = 0;
    Node<Ingredient *> *cur_ptr = getHeadNode();
    while ((cur_ptr != nullptr))
    {
        price += cur_ptr->getItem()->price_ * cur_ptr->getItem()->quantity_;
        cur_ptr = cur_ptr->getNext();
        std::cout << price << std::endl;
    }
    return price;
    ;
}

/**
@param: A const string reference to a filter with a default value of "NONE".
@post: With default filter "NONE": Print out every ingredient in the list.
With filter "CONTAINS":   Only print out the ingredients with >0 instances in the list.
With filter "MISSING": Only print out the ingredients with 0 instances in the list.
With filter "CRAFTABLE":  Only print out the ingredients where you have all the ingredients to craft them.
If an invalid filter is passed, print "INVALID FILTER\n"
Printing ingredients should be of the form:

[Ingredient name]: [Quantity]
[Ingredient description]\n
Price: [price]\n
Recipe:\n
[Ingredient0] [Ingredient1]\n\n

If the ingredient has no recipe, print "Recipe:\nNONE\n\n" after the price.
*/
void Pantry::pantryList(const std::string &filter) const
{
    if (filter == "NONE" || filter == "CONTAINS" || filter == "MISSING" || filter == "CRAFTABLE")
    {
        Node<Ingredient *> *cur_ptr = getHeadNode();
        while ((cur_ptr != nullptr))
        {
            if (filter == "NONE" || (filter == "CONTAINS" && cur_ptr->getItem()->quantity_ > 0) ||
                (filter == "MISSING" && cur_ptr->getItem()->quantity_ == 0) || (filter == "CRAFTABLE" && canCreate(cur_ptr->getItem())))
                printIngredient(cur_ptr->getItem());
            cur_ptr = cur_ptr->getNext();
        }
    }
    else
        std::cout << "INVALID FILTER\n";
}