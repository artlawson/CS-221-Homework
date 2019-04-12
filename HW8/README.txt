README

Arthur Lawson & Ian Jackson

Initially we used one of our own code for HTree and HForrest, but after
an infinite loop in one of our helper functions, we decided to use 
Eitan's code for both. 

In Huffman.cc, the main issues we encountered were with debugging encoder.
The aforementioned infinte loop was the most time consuming problem, but we 
also ran into issues while testing the encoder that we believe were caused by
the way we implemented our tree and placed our EOF.

For bitio, we followed the structure of the hh file while implementing private 
elements based off of reccomendations from Dylan and bugs we encountered along the way. 

For our Encoder/Decoder, we used the slides given in class and a lot of
online research to give us the proper format and syntax for reading 
in and outputting files.


COMPRESSION TESTS
-----------------


FILENAME:			| a.tst  || sentence.tst  || escape.txt || lorem_ipsum.txt | 
FILE SIZE:			| 2 bytes|| 25 bytes      || 1.9KB      || 29KB    	   |
COMPRESSED FILE SIZE:  		| NULL   || NULL	  || NULL       || NULL    	   |
DECOMPRESSED MATCH?:		| No     || No 		  || No         || No      	   |



Bugs:

Encoder: Upon testing encoder.cc against small test files (such as a.tst), we came across an
infinite loop. Further debugging revealed that this is likely due to inp.get() returning -1
in line 29 of the .cc file. Because -1 is not a symbol in the Huffman tree, this could not
be found. The debugger also mentioned something about add_tree in hforest.cc relating to this bug.
