/*
ArrayBag interface for term project
CSCI 235 Spring 2024
*/
#ifndef ARRAY_BAG_
#define ARRAY_BAG_
#include <iostream>
#include <vector>

template <class ItemType>
class ArrayBag
{

public:
    ArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType &new_entry);
    bool remove(const ItemType &an_entry);
    void clear();
    bool contains(const ItemType &an_entry) const;
    int getFrequencyOf(const ItemType &an_entry) const;

    void operator/=(const ArrayBag<ItemType> &a_bag);
    void operator+=(const ArrayBag<ItemType> &a_bag);

protected:
    static const int DEFAULT_CAPACITY = 100; // max size of items_ at 100 by default for this project
    ItemType items_[DEFAULT_CAPACITY];       // Array of bag items
    int item_count_;                         // Current count of bag items
    int getIndexOf(const ItemType &target) const;

}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
