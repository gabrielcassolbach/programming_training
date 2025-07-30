CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

SRCS = a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp h.cpp i.cpp j.cpp k.cpp l.cpp m.cpp

# Remove .cpp to get program names
PROGS = $(SRCS:.cpp=)

# Default target: build all programs
all: $(PROGS)

# Rule: compile each .cpp to its own executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up
clean:
	rm -f $(PROGS)