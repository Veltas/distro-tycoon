CXXFLAGS = -std=c++14 -Wall -W -pedantic -O3

distro-tycoon: main.cpp
	$(CXX) $(CXXFLAGS) `pkg-config --cflags gtk+-3.0` -o $@ $^ `pkg-config --libs gtk+-3.0`

