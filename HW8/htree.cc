#include "htree.hh"
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

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
    if (dir==LEFT)
    {
        return left_;
    }
    if (dir==RIGHT)
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
    if (get_child(LEFT))
    {
        if (get_child(LEFT)->is_key(key))
        {
         return get_child(LEFT)->is_key(key);
        }
    }
    if (get_child(RIGHT))
    {
        return get_child(RIGHT)->is_key(key); //checks right side of node

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
                //path.insert(path.end(), Direction:: LEFT); //increases list 'path,' same as line 71
                path.insert(path.end(), int(LEFT));
                left_ -> path_to(key);
            }
            if (right_ && right_ -> is_key(key))
            {
                //path.insert(path.end(), Direction:: RIGHT);
                path.insert(path.end(), int(RIGHT));
                right_ -> path_to(key);

            }
        return path;
        }
        else
        {
            assert(false); // if key is not found on any child of the tree
        }
        
    }


    void HTree::inorderWalk() {
        if (this != NULL) {
	    auto left = *(this->left_);
            left.inorderWalk();
            std::cout<< this->get_key() << std::endl;
	    auto right = *(this->right_);
	    right.inorderWalk();
	}
    }

int HTree::node_at(std::vector<bool> path) {
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


