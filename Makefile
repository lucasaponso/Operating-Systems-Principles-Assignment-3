CXX = g++
CXXFLAGS = -std=c++11
SRC_FILES = src/main.cpp src/Loader.cpp src/Syscall.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE_FIRSTFIT = firstfit
EXECUTABLE_BESTFIT = bestfit

# By default, use "firstfit" strategy
all: $(EXECUTABLE_FIRSTFIT)

# Rule to compile with "firstfit" strategy
$(EXECUTABLE_FIRSTFIT): CXXFLAGS += -DFIRSTFIT
$(EXECUTABLE_FIRSTFIT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXECUTABLE_FIRSTFIT)

# Rule to compile with "bestfit" strategy
$(EXECUTABLE_BESTFIT): CXXFLAGS += -DBESTFIT
$(EXECUTABLE_BESTFIT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXECUTABLE_BESTFIT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE_FIRSTFIT) $(EXECUTABLE_BESTFIT)
