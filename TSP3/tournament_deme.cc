#include "tournament_deme.hh"
#include <random>
#include "chromosome.hh"

Chromosome* TournamentDeme::select_parent() 
{
    auto top_parent = pop_[0]; //initializes top_parent
    std::vector<Chromosome*> winners;
    while (winners.size() < pop_.size() / 2)
    {
        int index1 = 0;
        int index2 = pop_.size() - 1;

        auto p1 = pop_[index1];// select  element in pop_
        auto p2 = pop_[index2];
        if (pop_.size() > 3) //only chooses 3 and 4 if there is more than 3 possible parents
        {
            int index3 = index1 + 1;
            int index4 = index2 - 1;

            auto p3 = pop_[index3]; 
            auto p4 = pop_[index4]; 
            if (p3 -> get_fitness() > p4 -> get_fitness()){winners.push_back(p3);}
            else {winners.push_back(p4);}
        }
        if (p1 -> get_fitness() > p2 -> get_fitness()) //sets top parent to winner between 1 and 2
        {
            winners.push_back(p1); //sends winner to winners bracket
        }
        else 
        {
            winners.push_back(p2);

        }
    }

    while (winners.size() > 1)
    {
        int index5 = 0;
        int index6 = winners.size() - 1;

        auto p1 = winners[index5];// select  element in pop_
        auto p2 = winners[index6];
        if (winners.size() > 3) //only chooses 3 and 4 if there is more than 3 possible parents
        {
            int index7 = index5 + 1;
            int index8 = index6 - 1;

            auto p3 = winners[index7]; 
            auto p4 = winners[index8]; 
            if (p3 -> get_fitness() > p4 -> get_fitness() ) {winners.erase(winners.end() - 2);}
            else {winners.erase(winners.begin() + 1);}
        }
        if (p1 -> get_fitness() > p2 -> get_fitness()) //sets top parent to winner between 1 and 2
        {
            winners.erase(winners.end() -1); //removes loser from winners bracket
            top_parent = p1; 
        }
        else 
        {
            winners.erase(winners.begin());
            top_parent = p2;
        }
    }    
    return top_parent;

}

