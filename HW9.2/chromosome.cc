/*
 * Implementation for Chromosome class
 */

#include <algorithm>
#include <cassert>
#include <random>
#include <memory>
#include <iostream>

#include "chromosome.hh"

/*
std::ostream& operator <<(Cities::permutation_t vector,std::ostream& out) {
	for(unsigned i=0;i<vector.size();i++) {
		out << vector[i] << ",";
	}
	out << std::endl;
	return out;
}
*/


//////////////////////////////////////////////////////////////////////////////
// Generate a completely random permutation from a list of cities
Chromosome::Chromosome(const Cities* cities_ptr)
  : cities_ptr_(cities_ptr),
    order_(random_permutation(cities_ptr->size())),
    generator_(rand())
{
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Clean up as necessary
Chromosome::~Chromosome()
{
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome
void
Chromosome::mutate()
{
  int index1 = generator_() % get_ordering().size(); //generate a random number between 0 and the size of the ordering to be indexed
  int index2 = generator_() % get_ordering().size();
  auto temp = order_[index1];
  order_[index1] = order_[index2]; //switch values at indices
  order_[index2] = temp;
  assert(is_valid()); //check if new order is valid
}

//////////////////////////////////////////////////////////////////////////////
// Return a pair of offsprings by recombining with another chromosome
// Note: this method allocates memory for the new offsprings
std::pair<Chromosome*, Chromosome*>
Chromosome::recombine(const Chromosome* other)
{
  assert(is_valid());
  assert(other->is_valid());
  auto rand_begin = generator_() % get_ordering().size(); //generate random numbers to begin and end
  auto rand_end = generator_() % get_ordering().size(); //tes me
  if (rand_begin > rand_end) { //control for case in which begin is greater than end. just makes it easier to read
	auto temp = rand_begin;
	rand_begin = rand_end;
	rand_end = temp;
  }
  Chromosome* child1 = create_crossover_child(this,other,rand_begin,rand_end); //create crossover children and swap parents
  Chromosome* child2 = create_crossover_child(other,this,rand_begin,rand_end);
  assert(child1->is_valid()); //check if children are valid!!!	
  assert(child2->is_valid());
  auto ret = std::make_pair (child1,child2);
  return ret;
}

//////////////////////////////////////////////////////////////////////////////
// For an ordered set of parents, return a child using the ordered crossover.
// The child will have the same values as p1 in the range [b,e),
// and all the other values in the same order as in p2.
Chromosome*
Chromosome::create_crossover_child(const Chromosome* p1, const Chromosome* p2,
                                   unsigned b, unsigned e) const
{
  Chromosome* child = p1->clone();

  // We iterate over both parents separately, copying from parent1 if the
  // value is within [b,e) and from parent2 otherwise
  unsigned i = 0, j = 0;

  for ( ; i < p1->order_.size() && j < p2->order_.size(); ++i) {
    if (i >= b and i < e) {
      child->order_[i] = p1->order_[i];
    }
    else { // Increment j as long as its value is in the [b,e) range of p1
      while (p1->is_in_range(p2->order_[j], b, e)) {
        ++j;
      }
      assert(j < p2->order_.size());
      child->order_[i] = p2->order_[j];
      j++;
    }
  }

  assert(child->is_valid());
  return child;
}

// Return a positive fitness value, with higher numbers representing
// fitter solutions (shorter total-city traversal path).
double
Chromosome::get_fitness() const
{
  return (1/(this->calculate_total_distance())); //make fitness the distance between cities using chromosome's permutation
}

// A chromsome is valid if it has no repeated values in its permutation,
// as well as no indices above the range (length) of the chromosome.
// We implement this check with a sort, which is a bit inefficient, but simple
bool
Chromosome::is_valid() const
{
  
  auto new_order = order_;
  std::sort(new_order.begin(),new_order.end());

  for(unsigned int i = 0;i<new_order.size();i++) { //check each number in order_ for repeats
	if(new_order[i] != i) {
		return false;
	}
  }

  return true;

}

// Find whether a certain value appears in a given range of the chromosome.
// Returns true if value is within the specified the range specified
// [begin, end) and false otherwise.
bool
Chromosome::is_in_range(unsigned value, unsigned begin, unsigned end) const
{
  for (unsigned i = begin; i<end; i++) {
	if (order_[i] == value) { 
		return true;
	}
  }
  return false;
}
