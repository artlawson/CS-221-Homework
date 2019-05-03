CXX=g++-7
CXXFLAGS=-g -Wall -Wextra -pedantic -Werror -std=c++17 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  tsp

tsp: tsp.o climb_chromosome.o chromosome.o deme.o cities.o tournament_deme.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh %.cpp
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o tsp
