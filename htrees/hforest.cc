#include "htree.hh"
#include "hforest.hh"
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) 
{
    return t1->get_value() < t2->get_value(); //given function by Eitan
}

unsigned HForest::size()
{
    return trees_.size(); //returns len of trees_
}
void HForest::add_tree(HTree::tree_ptr_t tree)
{
   trees_.push_back(tree);
   std::make_heap(trees_.begin(), trees_.end(), compare_trees);
}
HTree::tree_ptr_t HForest::pop_tree()
{
    HTree::tree_ptr_t top = trees_[0];
    trees_[0] = trees_[trees_.size() - 1]; //puts top in a position to be deleted
    trees_.pop_back();
    std::make_heap(trees_.begin(), trees_.end(), compare_trees);
    return top;
}


