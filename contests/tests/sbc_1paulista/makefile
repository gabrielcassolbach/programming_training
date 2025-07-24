CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

SRCS = A.cpp B.cpp C.cpp D.cpp E.cpp F.cpp G.cpp H.cpp I.cpp J.cpp K.cpp L.cpp M.cpp N_2.cpp

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