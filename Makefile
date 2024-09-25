# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -I./include

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable name
EXECUTABLE = $(BIN_DIR)/cppMinesweeper.exe

# Main target
all: $(EXECUTABLE)

# Rule to link the executable
$(EXECUTABLE): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@

# Rule to compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean

# Dependencies
$(OBJ_DIR)/GameManager.o: $(SRC_DIR)/GameManager.cpp $(INCLUDE_DIR)/GameManager.h $(INCLUDE_DIR)/Tilemap.h $(INCLUDE_DIR)/Tile.h
$(OBJ_DIR)/Tilemap.o: $(SRC_DIR)/Tilemap.cpp $(INCLUDE_DIR)/Tilemap.h $(INCLUDE_DIR)/Tile.h
$(OBJ_DIR)/Tile.o: $(SRC_DIR)/Tile.cpp $(INCLUDE_DIR)/Tile.h