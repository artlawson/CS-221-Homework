#include "htree.hh"
#include <string>
#include <iostream>
#include <cassert>

HTree::HTree(int key,
        uint64_t value,
        tree_ptr_t left,
        tree_ptr_t right)
        :key_(key), value_(value),left_(left),right_(right)
    {}

HTree::~HTree() = default;

    
int HTree::get_key() const 
    {
    return key_;
    }
uint64_t HTree::get_value() const
    {
    return value_;
    }
 
HTree::tree_ptr_t HTree::get_child(HTree::Direction dir) const
  {
    if (dir==Direction::LEFT)
    {
        return left_;
    }
    if (dir==Direction::RIGHT)
    {
        return right_;
    }
    return nullptr;
  }
bool HTree::is_key(int key) const // helper function, checks to see if key is on the either side of current tree
{
    if (key == key_)
    {
        return true;
    }
    if (get_child(Direction::LEFT))
    {
        if (get_child(Direction::LEFT)->is_key(key))
        {
         return get_child(Direction::LEFT)->is_key(key);
        }
    }
    if (get_child(Direction::RIGHT))
    {
        return get_child(Direction::RIGHT)->is_key(key); //checks right side of node

    }
    return false;
}
HTree::path_t path;
HTree::path_t HTree::path_to(int key) const
    { 
        

        if(is_key(key))
        {

            if (left_ && left_ -> is_key(key)) // uses helper function to check if key is on that side of the tree
            {
                path.insert(path.end(), Direction:: LEFT); //icreases list 'path,' same as line 71
                left_ -> path_to(key);
            }
            if (right_ && right_ -> is_key(key))
            {
                path.insert(path.end(), Direction:: RIGHT);
                right_ -> path_to(key);

            }
        return path;
        }
        else
        {
            assert(false); // if key is not found on any child of the tree
        }
        


    }





