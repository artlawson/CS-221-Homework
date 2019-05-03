#include <iostream>
#include "climb_chromosome.hh"


void ClimbChromosome::mutate()
{
    auto new_order = order_; //creates a copy of order_ for second manipulation
    auto newest_order = order_; // creates a copy of order for final manipulation
    double cur_fit = this -> get_fitness(); //stores current chromosome fitness
    unsigned int rand_point = generator_() % get_ordering().size(); // picks a random index in the chromosome
    auto temp = order_;
/////////////NEWWWWWW///////////
    if (rand_point == 0) //if rand_point is the first element, switch it with the last
    {
        std::swap(order_[rand_point], order_[order_.size() - 1]);
    }
    else
    {
      
        std::swap(order_[rand_point], order_[rand_point - 1]);
    }
    
    double new_fit = this->get_fitness(); // gets new fitness after swap
    new_order = order_;
    order_ = temp; //resets order_ for newest_fit to use
//////////////////NEWESTTTTTTT///////
    if(rand_point == order_.size() - 1) //if rand_point is the last element, swap with the first
    {
      
        std::swap(order_[rand_point], order_[0]);
    }
    else
    {
     
        std::swap(order_[rand_point], order_[rand_point + 1]);
    }
    double newest_fit = this->get_fitness(); // gets fitness for final mutation
    newest_order = order_;
    order_ = temp; //resets order

    if(new_fit > cur_fit && new_fit > newest_fit)
    {
        //std::cout<< "apple"<<std::endl;
        order_ = new_order; //I am 99% sure this will not work, but this if statement needs to replace the current order with the improved one
    }
    if(newest_fit > cur_fit && newest_fit > new_fit)
    {
        //std::cout<< "orange"<<std::endl;
        order_ = newest_order; //I am 99% sure this will not work, but this if statement needs to replace the current order with the improved one
        ///UPDATE IT WORKED!!!!!!
    }
    else {
        //std::cout<< "pineapples"<<std::endl;
	order_ = temp;
    }




}
