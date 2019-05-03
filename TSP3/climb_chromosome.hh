#include "chromosome.hh"

class ClimbChromosome : public Chromosome 

{
public:
    ClimbChromosome(const Cities* cities_ptr)
   : Chromosome(cities_ptr)
   {}
    virtual ~ClimbChromosome() = default;

    virtual double get_fitness() const//inherits get_fitness from chromosome.hh
   {
    return Chromosome::get_fitness();
   }

    virtual void mutate() override;

    virtual ClimbChromosome* clone() const override
  {
    return new ClimbChromosome(*this);
  }

};
