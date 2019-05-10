Ian Jackson & Arthur Lawson

* We used Eitan's starter code for this assignment*

It was a big help that we had the randomized search example to refer to. We reus.ed it and modified it for ga_search

Results started to flatline with the parameters: 1000 pop size, .3 mut rate, 4 threads.

|Number of Cores| time (sec)|distance|
|---------------|:---------:|-------:|
|   1           |  19.83    |6043.17 |
|   2           |  9.62     |6593.72 |
|   4           |  7.01     |5640.77 |
|   8           |  8.12     |6509.45 |

bugs:
The biggest bug we encountered was the number of threads defaulting to one no matter what we inputted. We realized that this was a
product of the the main function and fixed it to set to whatever argument is passed.

The next bug we encountered was best_ordering always returning 0, thus making shortest.tsv buggy. Initially, we set best_ordering
to be all zeros, so it makes sense that there was no ordering that would best the total distance of 0. We set it to be a random
permutation instead.