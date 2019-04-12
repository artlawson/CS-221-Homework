/*
 * A simple class to perform stream I/O on individual bits.
 * Before reading any bits, ensure your input stream still has valid inputs.
 */

#include <iostream>
#include "bitio.hh"
#include <cassert>	

// Construct with one of either an input stream or output (the other null)
//stream will only let characters through
BitIO::BitIO(std::ostream* os, std::istream* is) {

assert(os == NULL or is == NULL); //assert that only one is not null
assert(not(os && is)); //assert that they are not both null

is_ = is;
os_ = os;


}

// Flushes out any remaining output bits and trailing zeros, if any:
BitIO::~BitIO() {

	if(os_ && bit_index_ != 0) { //if this is an output object with remaining bits in the buffer, create a mask to fill the buffer
		  //with trailing zeros, and output to os. then flush os.
	//buffer_ = buffer_ << bit_index_; //shift buffer over by bit index to fill it to 8 bits
	os_->put(buffer_); //output to os
	//os_->flush(); //flush os
	}
}

// Output a single bit (buffered)
//every 8 times someone writes output bit, we want to output to os
//and restart count
void BitIO::output_bit(bool bit) {

	if (bit_index_ < 8) { //(next empty index)
		if (not bit) { //if we're setting a zero just go to the next index
			bit_index_++;
		}

		else { //if we're setting a one, create a mask and "AND" the buffer with the mask
			char mask = 1 << bit_index_;
			buffer_ = buffer_ | mask; //for some reason buffer isn't working here. std::cout << buffer prints a newline
			bit_index_++;
		}
	}

	if (bit_index_ == 8) { //if we're at the end, output to stream
		os_->put(buffer_); //output buffer
		buffer_ = 0; //reset buffer and bit index
		bit_index_ = 0;
	}

}

// Read a single bit (or trailing zero)
bool BitIO::input_bit() {

	if (bit_index_ == 0) { //if we are done reading, get another byte

		buffer_ = is_->get(); //get full byte from input stream
	}
	
	int current_bit = (buffer_ >> bit_index_)  & 1; //shift buffer by bit index and mod 2 to find desired bit
	bit_index_++;
	if (bit_index_ == 8){
		bit_index_ = 0; // reset bit_index_
		buffer_ = 0;
	}

	if (current_bit == 1) { //if the bit is one, return true
		return true;
	}
	
	else {
		return false;

	}
}
