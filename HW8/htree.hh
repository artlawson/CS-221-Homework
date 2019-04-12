/*
 * HTree: a class to represent a tree node with two elements: a key
 * and a value.
 */

#pragma once
#include <iostream>
#include <cassert>
#include <memory>
#include <list>
#include <vector>

class HTree {
 public:
  using tree_ptr_t = std::shared_ptr<const HTree>;
  enum Direction { LEFT, RIGHT };
  using path_t = std::list<int>;

  // Initialize with a key and a value:
  HTree(int key, uint64_t value, tree_ptr_t left = nullptr, tree_ptr_t right = nullptr)
    : key_(key), value_(value), left_(left), right_(right)
  { }

  ~HTree() = default;
  HTree(const HTree&) = default;
  HTree(HTree&&) = default;
  HTree& operator=(const HTree&) = delete;
  HTree& operator=(HTree&&) = delete;

  int get_key() const { return key_; }  // Return key in current node
  uint64_t get_value() const { return value_; }      // Return value in current node

  // Return the child of this node indicated by dir
  tree_ptr_t get_child(Direction dir) const
  {
    return (dir == Direction::LEFT)? left_ : right_;
  }

  // Crashes (with an assert) if key not contained in this tree
  path_t path_to(int key) const
  {
    assert(find(key));

    path_t ret;
    if (key_ != key) {
      if (left_ && left_->find(key)) {
        ret = left_->path_to(key);
        ret.push_front(int(LEFT));
      } else {              // key must be in right_
        ret = right_->path_to(key);
        ret.push_front(int(RIGHT));
      }
    }
    return ret;
  }
  int node_at(std::vector<bool> path) {
  std::vector<bool>::iterator at = path.begin();
  tree_ptr_t current(this);
  while (at != path.end()) {
    if (*at == 0) {
      current = current->get_child(LEFT);
      at++;
    }
    else if (*at == 1) {
      current = current->get_child(RIGHT);
      at++;
    }
  }
  return current->get_key();
}

 private:
  int key_;
  uint64_t value_;
  tree_ptr_t left_, right_;

  // Return true IFF the given key is contained somewhere in my tree
  bool find(int key) const
  {
    return key_ == key
       || (left_ && left_->find(key))
       || (right_ && right_->find(key));
  }

};
   /* void inorderWalk() {
        if (this != nullptr) {
      auto left = *(this->left_);
            left.inorderWalk();
            std::cout<< this->get_key() << std::endl;
      auto right = *(this->right_);
      right.inorderWalk();
  }
    }
    */




