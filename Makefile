CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src
OBJ_DIR = obj
EXECUTABLE_FIRSTFIT = firstfit
EXECUTABLE_BESTFIT = bestfit

# List of source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Create a list of object files by replacing .cpp with .o
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Rule to compile with "firstfit" strategy
$(EXECUTABLE_FIRSTFIT): CXXFLAGS += -DFIRSTFIT
$(EXECUTABLE_FIRSTFIT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

# Rule to compile with "bestfit" strategy
$(EXECUTABLE_BESTFIT): CXXFLAGS += -DBESTFIT
$(EXECUTABLE_BESTFIT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

# Compile each .cpp file into a .o file and save it in the obj/ directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the obj/ directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Add an "all" target that depends on both executables
all: $(EXECUTABLE_FIRSTFIT) $(EXECUTABLE_BESTFIT)

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE_FIRSTFIT) $(EXECUTABLE_BESTFIT)
