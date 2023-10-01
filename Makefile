CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17

all: firstfit bestfit

firstfit: src/main.cpp src/Loader.cpp
	$(CXX) $(CXXFLAGS) -o firstfit src/main.cpp src/Loader.cpp

bestfit: src/main.cpp src/Loader.cpp
	$(CXX) $(CXXFLAGS) -o bestfit src/main.cpp src/Loader.cpp

clean:
	rm -f firstfit bestfit
