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

int main(int argc, char** argv) {

for(int i=1;i<argc;i++) { //compress each file in the argument

    std::string input_filename = argv[i]; //get name of input file
    std::string comp = ".comp";
    Huffman huff; //create huffman encoder object

    std::ofstream out; //set up output file stream
    std::ifstream inp; //set up input file stream

    inp.open(input_filename); //open input file
    out.open(input_filename + comp); //open outfile

    BitIO reader(&out,nullptr); //create istream reader for reading from file one bit at a time
    
    while (true) { //while we can read from file, get characters and encode them
	int symbol = inp.get(); //read a character from the file
	if (symbol == -1) { //for some reason -1 is read at the end of the file
		break;
	}
            Huffman::bits_t encoded_symbol = huff.encode(symbol); //encode the character
            for (bool x:encoded_symbol) { //for each bit in new representation, output to output file
                reader.output_bit(x); //bit by bit, put into output file
            }

    }

}
}
