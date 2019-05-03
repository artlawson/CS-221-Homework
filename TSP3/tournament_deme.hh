#pragma once

#include "chromosome.hh"
#include "cities.hh"
#include "climb_chromosome.hh"
#include "deme.hh"
#include <random>

class TournamentDeme : public Deme {
 public:
    TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate) 
    : Deme(cities_ptr, pop_size, mut_rate) {}

    ~TournamentDeme() = default;

    virtual Chromosome* select_parent() override; //mama we made it

};