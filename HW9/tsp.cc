#include "cities.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

Cities::permutation_t random_permutation(unsigned len) {
	Cities::permutation_t output;
	for(unsigned int i=0;i<len;i++) { //make initial vector
		output.push_back(i);
	}
	std::random_shuffle (output.begin(), output.end());
	return output;
}

int main(int argc, char** argv) {
	//checks if there is only main arg
	if (argc < 2) {
		std::cerr << "Need an argument!";
		return -1;
	}
	//checks if there is more than input file arg
	if (argc > 2) {
		std::cerr << "Must have only one argument";
		return -1;
	}

	std::ifstream inp(argv[1]); //opens the input file
	if (!inp.is_open()) {
		std::cerr << "Can't open the file! " << argv[1]
 << "!\n";
		return -2;
	}

	std::ofstream out("speed.tsv"); //setup output file for shortest path(s)
	if (!out.is_open()) {
		std::cerr << "Can't open the output file speed.tsv" << "!\n";
		return -3;
	}
	
	Cities cities; //make cities object
	inp >> cities; //read input file into cities object
	Cities::permutation_t best_ordering = random_permutation(cities.get_cities().size()); //create a random permutation that is the size of the cities list
	int iterations = pow(10.0,6.0); //set iterations
	double best_distance = cities.total_path_distance(best_ordering); //find distance of the current best ordering
		out << "0" << " " << best_distance << std::endl;	
		for(int i = 1;i<iterations;i++) { //cycle through random permutations of cities, saving the best_distance each time
			Cities::permutation_t new_ordering = random_permutation(cities.get_cities().size()); //create a random permutation to be the new ordering
			//cities = cities.reorder(new_ordering); //reorder cities in current cities object, according to random ordering, and rewrite to object
			double new_ordering_distance = cities.total_path_distance(new_ordering); //find distance of random ordering in new city object
			if(new_ordering_distance < best_distance) { //check if randomised ordering distance is less than the best one
				best_distance = new_ordering_distance; //if so, replace best distance with randomised one
				best_ordering = new_ordering; //replace ordering
				out << i << " " << best_distance << std::endl; //print iteration number and best distance to output file
			}
	
		}
	return 1738;
}
