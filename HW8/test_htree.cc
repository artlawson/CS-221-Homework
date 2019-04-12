#include "htree.hh"
#include <iostream>
#include <string>
using tree_ptr_t = std::shared_ptr<const HTree>;
using path_t = std::list<int>;
/*
std::string get_direction(HTree::Direction entry) {
        
    std::string left = 0;
    std::string right = 1;

    if (entry == HTree::Direction{0}) {
        return left;
    }

    else if (entry == HTree::Direction{1}) {
        return right;
    }

    else {
        return "";
    }
}
*/
int main()
{

    HTree* tree10 = new HTree(10, 10); // creates basic tree
    //tree10.key_ = 0;
    //tree10.value_ = 20;
    
    HTree* tree9 = new HTree(9, 30, nullptr, nullptr);
    tree_ptr_t left = tree_ptr_t (tree9);
    tree_ptr_t right = tree_ptr_t (tree10);
    HTree* tree8 = new HTree(8, 40, left, right );
    HTree* tree7 = new HTree(7, 50);
    HTree* tree6 = new HTree(6, 60);
    left = tree_ptr_t (tree7);
    right = tree_ptr_t (tree6);
    HTree* tree5 = new HTree(5, 70, left, right);
    left = tree_ptr_t (tree5);
    right = tree_ptr_t (tree8);
    HTree* tree4 = new HTree(4, 80, left, right); //root of tree




/////////////////// example tests path to



    path_t x = tree4->path_to(6);
    for (int dir: x)
    {
        std::cout<< dir <<std::endl;
    };


////////////////// example 


    return 0;
}
