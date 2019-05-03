Ian Jackson & Arthur Lawson

*We used Eitan's code to start with.

                design:
The only major design decision we made was to have a 
tournament that does 4 competitions at a time in 
TournamentDeme. It may not be the most efficient route,
but it was easy to maintain.

                bugs:

Most of the bugs we faced this time around were simple inheritence errors in 
both ClimbChromosome and TournamentDeme.

Later we discovered some core dumps that came with us intially deleting members 
of the population in our select_parent function.

                Testing:
(The best results for all tests (except TournamentDeme & 
ClimbChromosome) came with 100 population and .1 mutation rate)

TournamentDeme and ClimbChromosome:
This of course gave us the most errors initially. After we
ironed out the bugs, we noticed some early convergence that
got better as we worked through it, but it was not as
good as some of the other combinations. It worked best with 
a low mutation rate and population around 20-40.

TournamentDeme & Chromosome:
In our tests, this combination proved to be the most efficient, consistent,
and best at computing consistently good distances.

Deme & Chromosome:
We mostly used this as a basis to compare everything else to. It was 
consistent and efficient, but it did not give us desirable distances.

Deme & ClimbChromosome:
This combination gave us the best and most consistent
results.
