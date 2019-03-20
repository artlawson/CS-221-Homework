#include "tree.hh"
#include <string>
#include <iostream>
#include <cassert>
tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left,
                       tree_ptr_t right)
    {
    tree_ptr_t new_Tree = new Tree(); // sets up creation of new tree with all aspects of tree outlined in struct
    new_Tree -> key_ = key; 
    new_Tree -> value_ = value;
    new_Tree -> left_ = left; 
    new_Tree -> right_ = right;
    return new_Tree;
    }

void destroy_tree(tree_ptr_t tree)
    { 
        if(tree -> left_ == nullptr && tree -> right_ == nullptr) // checking to see if you are at the bottom of the tree
            {
                delete tree; // deletes tree going back up

            }

        else
        {
            destroy_tree(tree -> left_); // recursively calls function on left side (next line on right side)
            destroy_tree(tree -> right_);
        }
    }
bool is_key( tree_ptr_t node, key_t key) // helper function, checks to see if key is on the either side of current tree
{
    if (key == node -> key_)
    {
        return true;
    }
    if (node -> left_)
    {
        if (is_key(node -> left_, key))
        {
         return is_key(node -> left_, key);
        }
    }
    if (node -> right_)
    {
        return is_key(node -> right_, key); //checks right side of node

    };
    return false;
}

std::string path_to(tree_ptr_t tree, key_t key)
    { 
        std::string path = " ";

        if(is_key(tree, key))
        {
            

            while (key != tree -> key_ )
            {
                if (is_key(tree -> left_, key)) // uses helper function to check if key is on that side of the tree (same as linr 56)
                {
                    
                    path+= "L" ; //icreases string 'path,' same as line 71
                    tree = tree -> left_;//moves through tree, same as line 72
                }
                else
                {
                    path+="R";
                    tree = tree -> right_;

                }
            }
        return path;
        }
        else
        {
            assert(false); // if key is not found on any child of the tree
        }
        


    }

tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
    if (path == " ")
    {
        return nullptr;
    }
    else
    {


        for ( char y : path) // iterates through string that is path
        { 
            
            if (y == 'L')
            {
                tree = tree -> left_; // sets x equal to left_ for next move down tree 
            }
            if (y == 'R')
            { 
                tree = tree -> right_; // sets x equal to right_ for next move down tree
            } 
            if (y != 'R' && y != 'L')
            {
                 return nullptr;


            }
             


        }
        return tree;

    }
}






