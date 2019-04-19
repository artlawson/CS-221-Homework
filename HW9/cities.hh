/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <tuple>
#include <fstream>
#include <iostream>

// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of the cities in cities_t. Each value represents a unique index
  // into the current city ordering.
  using permutation_t = std::vector<unsigned int>;

 //Overload stream shift right operator to allow for reading of Cities object into a stream
   friend std::istream& operator>>(std::istream& is, Cities& cities);

  //Overload stream shift left operator to allow for output of Cities object into a stream
  friend std::ostream& operator<<(std::ostream& os,Cities& cities);


  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;
 //getter function to return private member, cities list
  std::vector<coord_t> get_cities() {
	return cities_list_;
  }
  
  private:
    std::vector<coord_t> cities_list_;
};
