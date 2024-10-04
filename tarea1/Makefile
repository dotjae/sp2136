# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -O2

# Target executable
TARGET = mergesort

# Source files
SRCS = mergesort.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Compile target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
