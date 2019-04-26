																																																																														/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#pragma once

#include "chromosome.hh"
#include "cities.hh"

#include <random>

class Deme {
 public:
  // Generate a Deme of the specified size with all-random chromosomes.
  // Also receives a mutation rate in the range [0-1].
  Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate);

  // Clean up as necessary
  virtual ~Deme();

  // Evolve a single generation of new chromosomes, as follows:
  // We select pop_size/2 pairs of chromosomes (using the select() method below).
  // Each chromosome in the pair can be randomly selected for mutation, with
  // probability mut_rate, in which case it calls the chromosome mutate() method.
  // Then, the pair is recombined once (using the recombine() method) to generate
  // a new pair of chromosomes, which are stored in the Deme.
  // After we've generated pop_size new chromosomes, we delete all the old ones.
  virtual void compute_next_generation();

  // Return a pointer to the chromosome with the highest fitness.
  const Chromosome* get_best() const;

 protected:
  // Randomly select a chromosome in the population based on fitness and
  // return a pointer to that chromosome.
  virtual Chromosome* select_parent();

  std::vector<Chromosome*> pop_;  // Population of Chromosomes
  double mut_rate_;  // Mutation rate (fraction in range [0,1])

  std::default_random_engine generator_; // A random number generator for the various methods
};
