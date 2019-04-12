#include "htree.hh"
#include "hforest.hh"
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) 
{
    return t1->get_value() > t2->get_value(); //given function by Eitan
}

void HForest::add_tree(HTree::tree_ptr_t tree)
{
   trees_.push_back(tree);
   std::make_heap(trees_.begin(), trees_.end(), compare_trees);
}
HTree::tree_ptr_t HForest::pop_tree()
{
  if (trees_.empty()) {
    return nullptr;
  }
  std::pop_heap(trees_.begin(), trees_.end(), compare_trees);
  auto ret = trees_.back();
  trees_.pop_back();
  return ret;
}
