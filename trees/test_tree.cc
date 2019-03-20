#include "tree.hh"
#include <iostream>
#include <string>
int main()
{
    tree_ptr_t tree10 = create_tree(0, 20, nullptr, nullptr); // creates basic tree
    tree_ptr_t tree9 = create_tree(1, 30, nullptr, nullptr);
    tree_ptr_t tree8 = create_tree(2, 40, tree9, tree10);
    tree_ptr_t tree7 = create_tree(3, 50, nullptr, nullptr);
    tree_ptr_t tree6 = create_tree(4, 60, nullptr, nullptr);
    tree_ptr_t tree5 = create_tree(5, 70, tree7, tree6);
    tree_ptr_t tree4 = create_tree(6, 80, tree5, tree8); //root of tree

/////////////////// example tests path to

    std::string x = path_to(tree4, 4); //test path too function for tree with currently 3 levels
    //std::string x = path_to(tree4, 5);
    //std::string x = path_to(tree4, 4);

    std::cout<< x << std::endl;
////////////////// example tests node_at
    //tree_ptr_t y = node_at(tree4, "");
    tree_ptr_t y = node_at(tree4, "L");
    //tree_ptr_t y = node_at(tree4, "LR");
    //tree_ptr_t y = node_at(tree4, "RR");
    std::cout<< y << std::endl;
    std::cout<< tree5 << std::endl; // compare this and previous value, they should be the same (change the tree number accordingly!!!!)
    //destroy_tree(tree4);



    return 0;
}
