#ifndef SKILLTREE_HPP
#define SKILLTREE_HPP

#include "BinarySearchTree.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <climits>
#include <sstream>
#include <vector>
#include <algorithm>
#include "BinarySearchTree.hpp"

struct Skill
{
    int id_;
    std::string name_;
    std::string description_;
    bool leveled_;

    // Default constructor
    Skill() : id_{0}, name_{""}, description_{""}, leveled_{false}
    {
    }

    Skill(const int &id, const std::string &name, const std::string &description, bool leveled) : id_{id}, name_{name}, description_{description}, leveled_{leveled}
    {
    }

    bool operator==(const Skill &skill)
    {
        if (id_ == skill.id_)
            return true;
        return false;
    }

    bool operator<(const Skill &lowskill)
    {
        if (id_ < lowskill.id_)
            return true;
        return false;
    }

    bool operator>(const Skill &bigskill)
    {
        if (id_ > bigskill.id_)
            return true;
        return false;
    }
};

class SkillTree : public BinarySearchTree<Skill>
{
public:
    SkillTree();
    SkillTree(const std::string &fileName);
    std::shared_ptr<BinaryNode<Skill>> findSkill(const int &find) const;
    bool addSkill(const Skill &skill);
    bool removeSkill(const std::string &name);
    void clear();
    int calculateSkillPoints(const int &idcalc);
    void balance();
    void preorderDisplay() const;

    // helper functions

    int getNodesUntilId(const int &id, std::shared_ptr<BinaryNode<Skill>> subtree_ptr);
    void getSkills(std::shared_ptr<BinaryNode<Skill>> subtree_ptr);
    std::vector<Skill> skillsInTree;
    void balanceHelper(int leftMiddle, int rightMiddle);
    void displayHelper(const std::shared_ptr<BinaryNode<Skill>> subtree_ptr) const;
};
#endif