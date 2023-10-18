CXX = g++
CXXFLAGS = -std=c++11
INC_DIR = -I./des
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TARGET = my_program

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
MAIN = main.cpp

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJECTS) $(BUILD_DIR)/$(MAIN:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(INC_DIR) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(MAIN:.cpp=.o): $(MAIN)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
