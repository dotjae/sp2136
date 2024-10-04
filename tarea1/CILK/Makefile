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

# Limpiar archivos de compilación
clean:
	rm -f $(TARGET) $(OBJS)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)
