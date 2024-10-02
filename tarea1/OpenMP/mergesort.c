#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right);  // Helper function to merge two halves
void mergeSort(int arr[], int left, int right);       // Function to perform merge sort

int main() {
    int size = 10;  // Define the size of the array
    int arr[size];

    

  omp_set_num_threads(2); // export OMP_NUM_THREADS=4
	
  #pragma omp parallel num_threads(3)
  {

    // Initialize the array with random elements
    srand(time(0));  // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 99
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call mergeSort (the function is unimplemented)
    mergeSort(arr, 0, size - 1);

    // Print the sorted array (after mergeSort is implemented)
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
		


	printf("The parallel region is executed by thread %d\n", omp_get_thread_num());
i
  }

	
    return 0;
}


void merge(int arr[], int left, int mid, int right) {

}


void mergeSort(int arr[], int left, int right) {

}



  omp_set_num_threads(2); // export OMP_NUM_THREADS=4
	
  #pragma omp parallel num_threads(3)
  {



	printf("The parallel region is executed by thread %d\n", omp_get_thread_num());
  }
	return 0;
}
