#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cilk/cilk.h>       
#include <cilk/cilk_api.h>

#define ARRAY_SIZE 1000000

// Función merge para combinar dos mitades en un solo arreglo
void merge(int A[], int lo, int mid, int hi) {
    // Tamaño de las mitades
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    // Instanciar arreglos temporales y llenarlos con sus respectivas mitades
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        L[i] = A[lo + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j]; // Comenzar desde mid + 1 para la mitad derecha

    int i = 0, j = 0, k = lo;

    // Añadir elementos ordenadamente al arreglo final
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    // Añadir elementos restantes al arreglo final
    while (i < n1) {
        A[k++] = L[i++];
    }
    while (j < n2) {
        A[k++] = R[j++];
    }

    free(L);
    free(R);
}

// Función mergesort paralela con CILK
void mergesort(int A[], int lo, int hi) {
    if (lo < hi) {  
        int mid = lo + (hi - lo) / 2;
        cilk_spawn mergesort(A, lo, mid);    // Ejecutar en paralelo
        mergesort(A, mid + 1, hi);           // Ejecutar en serie
        cilk_sync;                           // Esperar a que terminen las tareas paralelas
        merge(A, lo, mid, hi);
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(0));

    // Llenar arreglos con números aleatorios de 0 a 999
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Obtener y mostrar el número de threads utilizados
    int num_threads = __cilkrts_get_nworkers();
    printf("Número de threads utilizados: %d\n", num_threads);

    // Medir el tiempo
    clock_t start_time = clock();
    mergesort(arr, 0, ARRAY_SIZE - 1);
    clock_t end_time = clock();

    // Tiempo tomado:
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTiempo: %f s\n", time_taken);

    return 0;
}
