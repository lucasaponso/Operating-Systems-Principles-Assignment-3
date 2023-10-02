CXX = g++
CXXFLAGS = -std=c++11
SRC_FILES = src/main.cpp src/Loader.cpp src/Syscall.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = firstfit

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
