#include <iostream>
#include "huffman.hh"
#include "hforest.hh"
#include "htree.hh"
#include <vector>


Huffman::Huffman(){
   
    FREQ_TABLE_ = std::vector<int>(ALPHABET_SIZE); //create Frequency Table of length alphabet size
    FREQ_TABLE_[HEOF] = pow(4.0,9.0); //make EoF reallyyy big!

}

void Huffman::make_tree(std::vector<int> FREQ_TABLE_){ //make huffman tree!!
    HForest huff_forest;
	for(int i=0;i<Huffman::ALPHABET_SIZE;i++) { //add single-node trees to forest
        	HTree::tree_ptr_t symbol_node(new HTree(i,FREQ_TABLE_[i]));
        	huff_forest.add_tree(symbol_node); //adds tree to forrest
	}	
	while (huff_forest.size() > 1) { //combine trees until there is one left
        auto left_symbol = huff_forest.pop_tree();
        auto right_symbol = huff_forest.pop_tree(); //pops trees with two lowest values
        //create new node with value as sum of symbols' frequencies
	   HTree::tree_ptr_t new_node(new HTree(-1, (left_symbol->get_value() + right_symbol->get_value()),left_symbol,right_symbol));
	   //add new node to huffman forest
        huff_forest.add_tree(new_node);
	}
	auto tree = (huff_forest.pop_tree()); //return huffman tree from forest
    curnode = tree;
	tree_ = tree;
	}

// Encode a symbol into a sequence of bits, then update frequency table.

Huffman::bits_t Huffman::encode(int symbol){

    make_tree(FREQ_TABLE_); //create huffman tree using updated frequency table
    bits_t output;
    for(auto x:tree_->path_to(symbol)) {
    	output.push_back(x);
    } //create path to symbol as type bits_t, which is a vector of 0s and 1s
    FREQ_TABLE_[symbol]++;
    return output;
}

// Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
// without additional bits, returns a negative value.
// Subsequent calls with more bits should eventually resolve to either
// a character symbol or HEOF.
// Finally, updates the frequency table with this additional symbol.

int Huffman::decode(bool bit){
      //increments pointer curnode depending on bit 
        if (curnode == nullptr) {
            make_tree(FREQ_TABLE_);
        }

        if (bit == 0) {
          curnode = curnode->get_child(HTree::LEFT);
        }
        else if (bit == 1) {
          curnode = curnode->get_child(HTree::RIGHT);
        }

    if (curnode->get_key() == -1) { //returns -1 if we are not at a symbol
        return -1;
    }
    else { //if we are at a symbol, return its key and remake tree :D
        int symbol = curnode->get_key();
        FREQ_TABLE_[symbol]++; //increment symbol frequency on table
        make_tree(FREQ_TABLE_); //make huffman tree with current frequency table
        return symbol;
    }

}
