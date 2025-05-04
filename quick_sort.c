
#include <stdio.h>

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    // Assuming the pivot to be the last element
    
    int i = low - 1;
    // Need the initial value of low index for swapping 
    // elements lesser than pivot

    for (int j = low; j < high; j++) {

        // Find the elements lesser than pivot
        if (arr[j] <= pivot) {
            i++;

            // Swap the element with the element at index i
            // to arrange the elements lesser than pivot
            // to the left of it.
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }

    // Swapping the pivot with the element currently 
    // occupying the appropriate position of the pivot element
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


int quick_sort(int arr[], int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }

    return 0;
}


int main() {

    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
