
#include <stdio.h>


int selection_sort(int arr[], int size) {

    // Best Case - O(n^2)
    // Worst Case - O(n^2)

    // even if you have an already sorted sequence

    for (int i = 0; i < size - 1; i++) { // size = n,

        int min_index = i;

        for (int j = i + 1; j < size; j++) { // n

            if (arr[j] < arr[min_index]) {
                min_index = j;
            }

        }

        // Swapping of minimum element with the first index of the 
        // unsorted portion of the array
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

    }

    return 0;
}


int main() {

    int arr[] = {29, 10, 14, 37, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
