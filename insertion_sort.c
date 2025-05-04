
#include <stdio.h>

int insertion_sort(int arr[], int size) {

    // Initial => [][29, 10, 14, 37, 14]

    // Don't want to use extra space
    // [29] [10, 14, 37, 14]
    // [10, 29] [14, 37, 14]
    // [10, 14, 29] [37, 14]
    // [10, 14, 29, 37] [14]
    // [10, 14, 14, 29, 37]

    // Insertion Sort

    // If the sequence is sorted, will the algorithm still run?
    // Worst Case Time Complexity is O(n^2)

    // For, already sorted sequence, will the internal while loop run n times?
    // No, it will have O(1) time complexity.
    // [1, 2, 3, 4, 5, 6]
    // [1] [2, 3, 4, 5, 6]
    // [1, 2] [3, 4, 5, 6] 
    // [1, 2, 3] [4, 5, 6]
    // Best Case Time Complexity is O(n)

    for (int i = 1; i < size; i++) { // O(n)

        int key = arr[i]; 
        // key element being considered to be inserted in to 
        // the sorted portion of the sequence (10)

        int j = i - 1;
        // Index of the last element of the sorted sequence (29)

        while (j >= 0 && arr[j] > key) { // O(n)
            arr[j + 1] = arr[j];
            // Creating space for key element to be inserted
            
            j--;
            // Keep going backwards
        }

        arr[j + 1] = key; // Insert the key element at the appropriate position
    }

    return 0;
}


int main() {

    int arr[] = {29, 10, 14, 37, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
