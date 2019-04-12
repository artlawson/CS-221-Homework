//This file's main function reads an input file, character by character,
//encodes each character, and outputs each encoding to an output file
//with suffix ".comp"
//Implements Huffman encoding to compress file size.

#include "htree.hh"
#include "hforest.hh"
#include "huffman.hh"
#include "bitio.hh"
#include <iostream>
#include <fstream>

int main(int argc,char** argv) {

	for(int i=1;i<argc;i++) { //decode each argument in the file

		std::string input_filename = argv[i]; //get name of input file
		std::string txt = ".plaintext";
		Huffman huff; //create huffman encoder object

		std::ofstream out; //set up output file stream
		std::ifstream inp; //set up input file stream

		inp.open(input_filename); //open input file
		out.open(input_filename + txt); //open outfile

		BitIO reader(nullptr,&inp); //create ostream reader for reading from file one bit

		while (inp.get()) { //while we can get from the input file, decode symbols bit by bit
		    int symbol;
		    while (symbol < 0) { //while we are not at a symbol, call decoder bit by bit
		    symbol = huff.decode(reader.input_bit());
		    }
		    if (symbol == Huffman::HEOF) { //if we're at the end, stop reading
	    		break;
		    }
	  	    else { //if we've reached a symbol, place it in the output file and start over
	    		out.put(symbol);
	    		symbol = -1;
	   	    }
	 	}
	}
}
