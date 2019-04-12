#include "htree.hh"
#include "hforest.hh"
#include <iostream>
#include <string>
#include <iterator>
using vector = std::vector<HTree::tree_ptr_t>;
using k_vector = std::vector<int>;
using v_vector = std::vector<uint64_t>;


HTree::tree_ptr_t make_tree(k_vector key, v_vector val)
{ 
    if (key.size() == 1)
    {
        std::shared_ptr<HTree> tree(new HTree(key[0],val[0]));
        HTree::tree_ptr_t  shared_tree = HTree::tree_ptr_t (tree);
        return shared_tree;

    }
    if (key.size() == 0 or val.size() == 0)
    {
        return nullptr;
    }
    if (key.size() == 2)
    {
        std::shared_ptr<HTree> c_tree(new HTree(key[0],val[0]));
        HTree::tree_ptr_t  leaf_tree = HTree::tree_ptr_t (c_tree); //converts to usable tree ptr
        std::shared_ptr<HTree> roote(new HTree(key[1], val[1], c_tree));
        HTree::tree_ptr_t  shared_root = HTree::tree_ptr_t (roote);
        return shared_root;

    }
    int root_key = key[0];
    uint64_t root_val = val[0];
    auto k_half_pt = key.size() / 2; // creates half-point for key vector

    k_vector::const_iterator k_midd(key.cbegin());
    std::advance(k_midd, k_half_pt);
    k_vector left_k(key.cbegin(), k_midd);
    k_vector right_k(k_midd, key.cend());

    auto v_half_pt = val.size() / 2; // creates half-point for key vector

    v_vector::const_iterator v_midd(val.cbegin());
    std::advance(v_midd, v_half_pt);
    v_vector left_v(val.cbegin(), v_midd);
    v_vector right_v(v_midd, val.cend());

    HTree::tree_ptr_t lp = make_tree(left_k, left_v);
    HTree::tree_ptr_t rp = make_tree(right_k, right_v);
    std::shared_ptr<HTree> root(new HTree(root_key, root_val, lp, rp));
    HTree::tree_ptr_t  deep_root = HTree::tree_ptr_t (root);
    return deep_root;


}
///list of keys in about to be used in make_tree
k_vector key0 = {1,2,3,4,5,6,7,8,9};
k_vector key1 = {2,4,6,8,10,12,16,18};
k_vector key2 = {3,9,12,15,18,21,24,27};
k_vector key3 = {318, 18, 3, 420, 69, 9, 1999, 31, 18};
///list of values about to be used in make_tree
v_vector val0 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
v_vector val1 = {20, 40, 60, 80, 100, 120, 140, 160, 180};
v_vector val2 = {30,90,120,150,180,210,240,270};
v_vector val3 = {1999, 2001, 2007, 2011, 1970, 1973, 2005, 1989, 1985};

//making trees with these vectors
HTree::tree_ptr_t tree0 = make_tree(key0, val0);
HTree::tree_ptr_t tree1 = make_tree(key1, val1);
HTree::tree_ptr_t tree2 = make_tree(key2, val2);
HTree::tree_ptr_t tree3 = make_tree(key3, val3);





int main()
{
    HForest gump;
    std::cout<< gump.size()<< std::endl; //should be 0, no trees added!
    gump.add_tree(tree0);
    gump.add_tree(tree1);
    gump.add_tree(tree2);
    gump.add_tree(tree3);

    std::cout<< gump.size()<< std::endl;
    gump.pop_tree();
    std::cout<< gump.size() << std::endl;
    std::cout<< gump.pop_tree()<< std::endl;
    std::cout<< gump.size()<< std::endl;

    return 0;
}