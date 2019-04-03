
CXX=g++-8
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all: test_htree test_hforest

test_htree: test_htree.o htree.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

test: all
	./test_htree
	./test_hforest

test_hforest: test_hforest.o hforest.o htree.o
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o test_hforest test_htree
