#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include "SkillTree.hpp"

int main()
{
    SkillTree skill("debug.csv");

    std::shared_ptr<BinaryNode<Skill>> found = skill.findSkill(1);
    if (found == nullptr)
        std::cout << "NOT found" << std::endl;
    else
        std::cout << "Found" << std::endl;

    // testing add skill
    Skill skillToAdd(6, "s6", "skill 6 ", false);
    skill.addSkill(skillToAdd);

    found = skill.findSkill(6);
    if (found == nullptr)
        std::cout << "NOT found" << std::endl;
    else
        std::cout << "Found" << std::endl;

    // testing remove skill
    std::cout << "removed: " << skill.removeSkill("s6") << std::endl;
    skill.preorderDisplay();
    found = skill.findSkill(6);
    if (found == nullptr)
        std::cout << "NOT found" << std::endl;
    else
        std::cout << "Found" << std::endl;

    // std::cout << "Height: " << skill.getHeight() << std::endl;
    // std::cout << "Height until id = 3: " << skill.calculateSkillPoints(3) << std::endl;
    // skill.preorderDisplay();
    skill.balance();
    skill.preorderDisplay();

    return 0;
}