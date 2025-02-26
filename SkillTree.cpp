#include "SkillTree.hpp"

/**
 * Default Constructor
 */
SkillTree::SkillTree() : BinarySearchTree<Skill>()
{
}

/**
 * @param: A const reference to string: the name of a csv file
 * @post: The SkillTree is populated with Skills from the csv file
 * The file format is as follows:
 * id,name,description,leveled
 * Ignore the first line. Each subsequent line represents a Skill to be added to the SkillTree.
 */
SkillTree::SkillTree(const std::string &fileName) : BinarySearchTree<Skill>()
{
    std::ifstream file(fileName);
    if (file.fail())
        exit(1);
    int id;
    std::string name, description, temp, holder;
    bool leveled;

    // deletes the first line
    std::getline(file, temp);
    while (std::getline(file, temp))
    {
        std::istringstream streamingSentence(temp);
        std::getline(streamingSentence, holder, ',');
        id = std::stoi(holder);
        std::getline(streamingSentence, name, ',');
        std::getline(streamingSentence, description, ',');
        std::getline(streamingSentence, holder, ',');
        std::istringstream streamingLeveled(holder);
        streamingLeveled >> leveled;
        Skill skill{id, name, description, leveled};
        addSkill(skill);
    }
    file.close();
}

/**
 * @param: A const reference to int representing the id of the Skill to be found
 * @return: A pointer to the node containing the Skill with the given id, or nullptr if the Skill is not found
 */
std::shared_ptr<BinaryNode<Skill>> SkillTree::findSkill(const int &id) const
{
    Skill targetSkill;
    targetSkill.id_ = id;
    return (findNode(getRoot(), targetSkill));
}

/**
 * @param: A const reference to Skill
 * @post: The Skill is added to the tree (in BST order as implemented in the base class) only if it was not already in the tree.
 *         Note that all comparisons are id-based as implemented by the Skill comparison operators.
 * @return: True if the Skill is successfully added to the SkillTree, false otherwise
 */
bool SkillTree::addSkill(const Skill &skill)
{
    if (findSkill(skill.id_) != nullptr)
        return false;

    // adds the skill
    add(skill);
    return true;
}

/**
 * @param: A const reference to string: the name of a Skill
 * @return: True if the Skill is successfully removed from the SkillTree, false otherwise
 */
bool SkillTree::removeSkill(const std::string &name)
{
    // std::cout << "hi" << std::endl;
    // if (findNodeWithName(getRoot(), name) == nullptr)
    //     return false;
    // removeNode(findNodeWithName(getRoot(), name));
    // return true;
    skillsInTree.clear();
    getSkills(getRoot());
    // std::cout << "need to find: " << name << std::endl;

    // std::cout << skillsInTree.size() << std::endl;
    for (int i = 0; i < skillsInTree.size(); i++)
    {
        // std::cout << skillsInTree[i].name_ << std::endl;
        if (skillsInTree[i].name_ == name)
        {
            // std::shared_ptr<BinaryNode<Skill>> nodeToRemove = findNode(getRoot(), skillsInTree[i]);
            // // std::cout << "node to remove name: " << nodeToRemove->getItem().name_ << std::endl;
            // int find = nodeToRemove->getItem().id_;
            remove(findNode(getRoot(), skillsInTree[i])->getItem());
            // std::cout << "is skill in the tree?: ";
            // if (findSkill(find) == nullptr)
            //     std::cout << "no" << std::endl;
            // else
            //     std::cout << "yes" << std::endl;

            return true;
        }
    }
    return false;
}

/**
 * @post: Clears the tree
 */
void SkillTree::clear()
{
    root_ptr_ = nullptr;
}

int SkillTree::getNodesUntilId(const int &id, std::shared_ptr<BinaryNode<Skill>> subtree_ptr)
{
    if ((subtree_ptr->getItem().id_ == id))
        return 1; // Found
    else if (subtree_ptr->getItem().id_ > id)
        // Search left subtree
        return 1 + getNodesUntilId(id, subtree_ptr->getLeftChildPtr());
    else
        // Search right subtree
        return 1 + getNodesUntilId(id, subtree_ptr->getRightChildPtr());
}
/**
 * @param: A const reference to int representing the id of a Skill
 * Note: For a Skill to be leveled up, its parent Skill must also be leveled up, thus the Skill points are the number of Skills
 * that must be leveled up before and including the Skill with the given id.
 * @return: an integer: the number of skill points needed to level up the Skill with the given id, starting from the root
 * (i.e. the number of nodes from root to the given Skill).
 * Include the Skill with the given id in the count. For example, if the tree contains the following Skills (represented by their ids):
 *   5
 *  / \
 * 1   8
 * and the function parameter queries for id 8, the function should return 2.
 * Disregard the leveled_ field of the existing Skills in the tree.
 * If the Skill with the given id is not found, return -1.
 */
int SkillTree::calculateSkillPoints(const int &id)
{
    if (findSkill(id) == nullptr)
        return -1;
    return getNodesUntilId(id, getRoot());
}

void SkillTree::getSkills(std::shared_ptr<BinaryNode<Skill>> subtree_ptr)
{
    if (subtree_ptr == nullptr)
        return;
    skillsInTree.push_back(subtree_ptr->getItem());
    getSkills(subtree_ptr->getLeftChildPtr());
    getSkills(subtree_ptr->getRightChildPtr());
}

void SkillTree::balanceHelper(int start, int end)
{
    // int middle;
    // if (((end - start) % 2) == 0)
    //     middle = ((end - start) / 2);
    // else
    //     middle = (int)((end - start) / 2) - 1;
    // if (middle >= 0 || middle <= (skillsInTree.size() - 1))
    // {
    //     addSkill(skillsInTree[middle + start]);
    //     balanceHelper(start, middle);
    //     balanceHelper(middle, end);
    // }
    // 0 1 2 3 4 5 6 7                   size = 8

    if (start > end)
        return;
    int middle = (start + end) / 2;
    addSkill(skillsInTree[middle]);
    balanceHelper(start, middle - 1);
    balanceHelper(middle + 1, end);
}

/**
 * @post: Balances the tree. Recall the definition of a balanced tree:
 * A tree is balanced if for any node, its left and right subtrees differ in height by no more than 1. * All paths from root of
 * subtrees to leaf differ in length by at most 1
 * Hint: You may sort the elements and build the tree recursively using a divide and conquer approach
 */
void SkillTree::balance()
{
    skillsInTree.clear();
    getSkills(root_ptr_);

    // // testing
    // // delete
    // for (int i = 0; i < skillsInTree.size(); i++)
    //     std::cout << skillsInTree[i].id_ << " ";
    // std::cout << std::endl;

    // order vector
    bool swap;
    Skill temp;
    do
    {
        swap = false;
        for (int i = 0; i < (skillsInTree.size() - 1); i++)
        {
            if (skillsInTree[i].id_ > skillsInTree[i + 1].id_)
            {
                temp = skillsInTree[i];
                skillsInTree[i] = skillsInTree[i + 1];
                skillsInTree[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    // testing
    // delete
    // for (int i = 0; i < skillsInTree.size(); i++)
    //     std::cout << skillsInTree[i].id_ << " ";
    // std::cout << std::endl;

    clear();
    balanceHelper(0, ((int)skillsInTree.size() - 1));

    // testing
    // skillsInTree.clear();
    // getSkills(root_ptr_);
    // for (int i = 0; i < skillsInTree.size(); i++)
    //     std::cout << skillsInTree[i].id_ << " ";
    // std::cout << std::endl;
}

void SkillTree::displayHelper(const std::shared_ptr<BinaryNode<Skill>> subtree_ptr) const
{
    if (subtree_ptr == nullptr)
        return;
    std::cout << subtree_ptr->getItem().id_ << " " << subtree_ptr->getItem().name_ << std::endl
              << subtree_ptr->getItem().description_ << std::endl
              << subtree_ptr->getItem().leveled_ << std::endl;
    // if (subtree_ptr->getItem().leveled_ == 0)
    //     std::cout << "FALSE" << std::endl;
    // else
    //     std::cout << "TRUE" << std::endl;
    std::cout << std::endl;
    displayHelper(subtree_ptr->getLeftChildPtr());
    displayHelper(subtree_ptr->getRightChildPtr());
}
/**
     * @post: prints the tree in preorder, in the format:
     [id_] [name_]\n
    [description_]\n
    [leveled_]
    */
void SkillTree::preorderDisplay() const
{
    displayHelper(root_ptr_);
}
