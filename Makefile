CXX = g++
CXXFLAGS = $(shell pkg-config --cflags gtkmm-3.0) -std=c++14 -Wall -W -pedantic -Ofast
MY_LIBS = $(shell pkg-config --libs gtkmm-3.0) -lX11

MY_OBJS = $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))

.PHONY: all
all: bin/distro-tycoon

bin/distro-tycoon: $(MY_OBJS) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^ $(MY_LIBS)

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin bin/tests obj obj/tests:
	mkdir $@

obj/tests: | obj
bin/tests: | bin

.PHONY: clean
clean:
	rm -rf bin/ obj/

test: -lcairomm
	echo $^
