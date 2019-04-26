README.txt
Ian Jackson & Arthur Lawson

We decided to use Eitan's code to start off HW10.
Most of the implementation issues we encountered were relatively
quick "Google" fixes.

The chromosome class was pretty to understand, but was not until
we got some insight from tutors that we gained a complete understanding
of the Deme class. We discovered while debugging that there were some
minor issues with our "recombine" and "next_generation" functions.

An added benefit to Eitan's code was that gnuplot worked a lot
smoother this time around. It was not perfect, but a few internet
searches later everything was working well.

bugs:
The biggest bug we encountered was attempting to optimize the 
best distance at the end. Previously we struggled a decent amount
attempting to make the improved distances print to the terminal.
In this process we gained a better understanding of Eitan's given
tsp file and the difference between the overriden "<<" operator vs
the "std<< cout."

We went to office hours to attempt to figure out why oour distances were
higher than expected. Eitan suggested checking recombine and making sure 
things were "random as they should be," but nothing worked out.