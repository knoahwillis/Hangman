PNAME := Hangman

PCXXSRC := $(wildcard src/*.cpp)

PCXXOBJ := $(PCXXSRC:.cpp=.o)

CXXFLAGS += -std=c++11 -O2 -g -Wall -Wpedantic

LDLIBS += 

LDFLAGS += 

CC := g++

.PHONY: all clean 

all: $(PCXXOBJ)
	$(CC) $(LDLIBS) $(PCXXOBJ) $(LDFLAGS) -o $(PNAME)
	$(RM) $(PCXXOBJ)

%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS) -o $@

clean:
	$(RM) $(PNAME)
