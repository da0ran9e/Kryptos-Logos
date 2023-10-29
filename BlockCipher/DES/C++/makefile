CXX = g++
CXXFLAGS = -std=c++11 -I./des

# Source file directories
SRCDIR = src
DESDIR = des

# Object file directory
BUILDDIR = build

# List of source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(DESDIR)/*.cpp) main.cpp

# List of object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Output executable
EXECUTABLE = crypto

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(DESDIR)/%.hpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(DESDIR)/%.cpp $(DESDIR)/%.hpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(EXECUTABLE)

.PHONY: all clean
