CXX=g++-8
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  tsp

tsp: tsp.o tournament_deme.o climb_chromosome.o chromosome.o deme.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^ -pthread

%.o.cc: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $< -j 8

clean:
	rm -rf *.o tsp
