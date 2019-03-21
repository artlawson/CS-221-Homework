CXX = g++
CCFLAGS = -g -std=c++14

# this is a "Suffix Rule" - how to create a .o from a .cc file
.cpp.o:
	$(CXX) $(CCFLAGS) -c $<

.cc.o:
	$(CXX) $(CCFLAGS) -c $<


highest: highest.o
	$(CXX) $(CCFLAGS) -o highest highest.o

all: source-stats.wc highest

source-stats.wc: source.txt
	wc source.txt > source-stats.wc

clean:
	rm -f *.o
	rm -f *-stats.wc
