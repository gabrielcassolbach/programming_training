# Generate an arithmetic sequence with a common difference of 2
def generate_arithmetic_sequence(start, difference, size):
    return [start + i * difference for i in range(size)]

# Parameters
start = 0
difference = 8
size = 200000

# Generate the sequence
sequence = generate_arithmetic_sequence(start, difference, size)

# Save the sequence to a .txt file
# Save the sequence to a .txt file (space-separated on one line)
with open("in2", "w") as file:
    file.write(" ".join(map(str, sequence)))

print("Sequence saved to 'in2'")