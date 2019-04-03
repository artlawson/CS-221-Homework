#include "htree.hh"
#pragma once
#include <memory>
#include <list>
#include <vector>

class HForest {
 public:
  HForest() = default;
  ~HForest() = default;
  unsigned size(); // returns the number of trees in the forest
  void add_tree(HTree::tree_ptr_t tree);
  HTree::tree_ptr_t pop_tree(); //returns largest largest tree and pops it

private:
    std::vector<HTree::tree_ptr_t> trees_; //vector that stores the trees in the forest

};