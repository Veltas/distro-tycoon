CXX = gcc
CXXFLAGS = $(shell pkg-config --cflags gtk+-3.0) -std=c++14 -Wall -W -pedantic -Ofast
LIBS = $(shell pkg-config --libs gtk+-3.0)

OBJS = $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))

.PHONY: all
all: bin/distro-tycoon

bin/distro-tycoon: $(OBJS) $(LIBS) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/main.o: src/main.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin bin/tests obj obj/tests:
	mkdir $@

obj/tests: | obj
bin/tests: | bin

.PHONY: clean
clean:
	rm -rf bin/ obj/

