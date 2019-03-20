/*
 * Tree: A simple recursive data structure to hold keys and values.
 */

#pragma once

#include <string>

using key_t = int;
using value_t = uint64_t;

struct Tree {
  key_t key_;
  value_t value_;
  Tree* left_;
  Tree* right_;
};

// Main type to access tree nodes (including the root):
using tree_ptr_t = Tree*;

//////////////////////////////////////////////////////////////////////////////
// create_tree allocates space for a new tree node and fills it with the given
// data parameters. By default, the tree is a leaf, so its children point to
// nullptr, but you may override with actual pointers to other nodes.
tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left = nullptr,
                       tree_ptr_t right = nullptr);

//////////////////////////////////////////////////////////////////////////////
// Deallocate all space consumed by this tree and its children.
void destroy_tree(tree_ptr_t tree);


//////////////////////////////////////////////////////////////////////////////
// path_to: return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
// So for example for the following tree (only keys depicted, values omitted):
/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9
*/
// path_to(tree, 9) will return "LRL", path_to(tree, 3) will return "R", and
// path_to(126) will return "".
// If the key isn't found in the tree, path_to should abort the program using an
// assert() call.
//
// If multiple matches to key exist in the tree, return the path to the
// leftmost match. For the tree above, path_to(tree, 12) returns "LL".
std::string path_to(tree_ptr_t tree, key_t key);

//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)
tree_ptr_t node_at(tree_ptr_t tree, std::string path);

