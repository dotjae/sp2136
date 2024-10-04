#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int num_threads;

// Funcion merge para combinar dos mitades en un solo arreglo
void merge(int A[], int lo, int mid, int hi) {
    // Tamano de las mitades
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    // Instanciar arreglos temporales y llenarlos con sus respectivas mitades
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        L[i] = A[lo + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = lo;

    // Anadir elementos ordenadamente al arreglo final
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    // Anadir elementos restantes al arreglo final
    while (i < n1) {
        A[k++] = L[i++];
    }
    while (j < n2) {
        A[k++] = R[j++];
    }

    free(L);
    free(R);
}

// Funcion mergesort paralelizada utilizando OpenMP
void mergesort(int A[], int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        // Paralelizar el ordenamiento de cada mitad del arreglo original
        #pragma omp parallel sections
        {
            #pragma omp task shared(A) if (hi-lo > 10000)
            mergesort(A, lo, mid);

            #pragma omp task shared(A) if (hi-lo>10000)
            mergesort(A, mid + 1, hi);
        }

	#pragma omp taskwait
        merge(A, lo, mid, hi);
    }
}



// Funcion para imrimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(0));
    
    // LLenar arreglos con numeros aleatorios de 0 a 999
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // printf("Arreglo original:\n");
    // printArray(arr, ARRAY_SIZE);

    // Medir el tiempo
    double start_time = omp_get_wtime();
    // clock_t start_time = clock();

    
    #pragma omp parallel // Se crea el equipo de threads
    {
        #pragma omp single 
	{ // Solo un thread llama a la funcion mergesor

	num_threads = omp_get_num_threads();
	printf("\nThreads utilizados: %d\n", num_threads);	
        mergesort(arr, 0, ARRAY_SIZE - 1);
	}
    }
     double end_time = omp_get_wtime();
    //clock_t end_time = clock();


    // printf("\nArreglo ordenado:\n");
    // printArray(arr, ARRAY_SIZE);
	
    // printf("\nThreads: %d", omp_get_thread_num());
    // Tiempo tomado:
    double time_taken = end_time - start_time;
    //double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nTiempo: %f s\n", time_taken);

    return 0;
}
