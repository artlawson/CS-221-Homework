README
Arthur Lawson & Ian Jackson

In the process of overridng the operators we needed, everything went as 
expected with only minimal bugs. Things were a little off when we tried to 
utilize certain things as member functions as oposed to methods. After 
this process, we referred to the slides and google often on working to
set up the input and output streams. 

The given methods and our helper functions such as reorder were pretty 
easily implemented. We initially created random permuatation as a free 
function, but we discovered that it worked a lot more seamlessly as a method.

Bugs:
Initially we had a lot of issues getting the gnuplot to work. After some 
adjustments to our output stream and extensive gdb sessions, we got 
everything to work.

We also had some miscalculations on our distance calculations that created great inconsistency depending on the size of the city list. 

compile code: g++ -g -Wall -Wextra -pedantic -std=c++17 tsp.cc cities.cc -o a.o
(speed.tsv is the output destination)