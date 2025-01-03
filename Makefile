# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude

# Directories
INCLUDES_DIR = include
SRC_DIR = src
BUILD_DIR = build

# Programs to build
PROGRAMS = main

# Common source files
COMMON_SRC = Hypercube.cpp EdmondsKarp.cpp
COMMON_OBJ = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(COMMON_SRC))

MAIN_SRC = main.cpp $(COMMON_SRC)

# Object files for each program
MAIN_OBJ = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(MAIN_SRC))

# Default target to build all programs
all: $(PROGRAMS)

# Rules for each program
main: $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule to compile .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up all build artifacts
clean:
	rm -rf $(BUILD_DIR) main

# Phony targets to avoid conflicts with file names
.PHONY: all clean