# Compiler
CC = gcc

# Compiler flags
# CFLAGS = -Wall -O2 -fopenmp -std=c99

CFLAGS = -fopenmp -std=c99 

# Target executable
TARGET = mergesort_omp

# Source files
SRCS = mergesort_omp.c

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

slurm2:
	sbatch submit.slurm

slurm4:
	sbatch submit_4.slurm

slurm8:
	sbatch submit_8.slurm

slurm16:
	sbatch submit_16.slurm

slurm32:
	sbatch submit_32.slurm

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET) openmp.*

# Run the program
run: $(TARGET)
	./$(TARGET)
