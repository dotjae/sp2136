# Makefile para compilar codigo.cpp con CILK Plus usando g++

# Compilador
CC = g++

# Flags del compilador
CFLAGS = -std=c++11 -Wall -fcilkplus

# Nombre del ejecutable
TARGET = mergesort_cilk

# Archivos fuente
SRCS = mergesort_cilk.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Target por defecto
all: $(TARGET)

# Regla para enlazar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


slurm:
	sbatch submit.slurm
	sbatch submit_4.slurm
	sbatch submit_8.slurm
	sbatch submit_16.slurm
	sbatch submit_32.slurm
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

# Limpiar archivos de compilación
clean:
	rm -f $(TARGET) $(OBJS) cilk*

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)
