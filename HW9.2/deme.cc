/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "chromosome.hh"
#include "deme.hh"
#include <cassert>

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
: mut_rate_(mut_rate),
  generator_(rand())
{
  for(unsigned int i=0;i<pop_size;i++) {
	Chromosome* chromosome = new Chromosome(cities_ptr); //make new Chromosome object w/ pointer
	pop_.push_back(chromosome); //add pointer to population of chromosomes
  }
}

// Clean up as necessary
Deme::~Deme()
{
  for(unsigned int i=0;i<pop_.size();i++) { //delete all pointers in vector of chromosomes
	delete pop_[i];
	pop_.clear();
  }
}

// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
  std::vector<Chromosome*> new_pop;
  while(new_pop.size() < pop_.size()) {
	auto parent1 = this->select_parent(); //select to random chromosomes to recombine
	auto parent2 = this->select_parent();
	auto probability1 = double((generator_()) / (RAND_MAX)); //make probabilities for mutation [0,1]
	auto probability2 = double((generator_()) / (RAND_MAX));
	if(probability1 <= mut_rate_) { //check each mutation probability and mutate if below threshold
		parent1->mutate();
	}
	else if(probability2 < mut_rate_) {
		parent2->mutate();
	}
	auto children = parent1->recombine(parent2); //recombine parents to make children
	auto child1 = children.first;
	auto child2 = children.second;
	new_pop.push_back(child1); //add children to new population
	new_pop.push_back(child2);
    

  }

  for(unsigned int i=0;i<pop_.size();i++) { //delete all pointers in vector of chromosomes
	delete pop_[i];
	pop_.clear(); //clear for good measure!!!
  }
  pop_ = new_pop; //replace old pop with new generation!
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
  auto best = pop_[0];
  for(unsigned int i=1; i<pop_.size();i++) { //loop through all pointers in population
	if(pop_[i]->get_fitness() > best->get_fitness()) {
		best = pop_[i]; //save best fitness
	}
  }
  return best;
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
  long double fitness_sum = 0;
  for(unsigned int i=0;i<pop_.size();i++) { //loop through population and find sum of all fitnesses
	fitness_sum += pop_[i]->get_fitness();
  }
  long double partial_sum = 0;
  //unsigned int threshold = generator_() % fitness_sum;
  double threshold = (fitness_sum) * ( (double)generator_() / (double)RAND_MAX ); //generate a random number in between 0 and fitness_sum
  //double threshold = fRand(0, fitness_sum);
  assert(threshold < fitness_sum);
  for(auto c : pop_) { //add fitnesses to partial sum until we find the index at which the partial sum exceeds the sum
	partial_sum += c->get_fitness();
    if (partial_sum > threshold) {
        return c; //return chromosome that passes threshold
    }
  }
  return nullptr;
}
