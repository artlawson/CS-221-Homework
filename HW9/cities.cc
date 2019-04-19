#include <iostream>
#include <fstream>
#include "cities.hh"
#include <cmath>
#include <algorithm>
#include <cassert>

//this function takes a cities object, reorders its cities_list_ into a new city object
Cities Cities::reorder(const permutation_t& ordering) const
 {
    Cities city;
  
    for(unsigned int i = 0; i < ordering.size(); ++i) //reorder cities list
    {
      city.cities_list_.push_back(cities_list_[i]);
    }
    
    return city;
  }

//this function finds the distance between all cities in a cities object and back around to the first index
  double Cities::total_path_distance(const permutation_t& ordering) const
{
    assert(cities_list_.size() == ordering.size()); //assert that we are comparing the same sized vectors
    double distance = 0;
    for(unsigned int i = 0; i < ordering.size() - 1; ++i) //add up distances between cities 0 to len-1
    {
      distance+=std::hypot((cities_list_[ordering[i+1]].first - cities_list_[ordering[i]].first),(cities_list_[ordering[i+1]].second - cities_list_[ordering[i]].second));
    }
    distance+=std::hypot((cities_list_[ordering.front()].first - cities_list_[ordering.back()].first),(cities_list_[ordering.front()].second - cities_list_[ordering.back()].second)); //add distance from city len-1 to city 0 (back around)
    return distance;
}

 std::ostream& operator<<(std::ostream& os,Cities& cities) { //overload << operator to output cities object
	std::string output;
	auto city_list = cities.get_cities();
	if (city_list.size() == 0) { //if city has no cities, print is empty
		os << "Cities Object is Empty";
	}
	else { //if not, print out each city's x value, with a space, then the y value
		unsigned int i = 0;
		while(i < city_list.size()) {
			os << city_list[i].first << " " << city_list[i].second;
i++;
		}
	}
	return os;
}

std::istream& operator>>(std::istream& is, Cities& cities) //overload operator >> to input cities object
{
	std::vector<Cities::coord_t> output_list; //create vector of coordinates to input
	int x;
	int y;
	while (is >> x) { //read in from tsp file an x and y value, make a pair from each, and add it to coordinates list
		is >> y;
		Cities::coord_t coordinates = std::make_pair(x,y);
		cities.cities_list_.push_back(coordinates); //add each new coordinate pair to cities object's cities list
	}
	return is;
}
