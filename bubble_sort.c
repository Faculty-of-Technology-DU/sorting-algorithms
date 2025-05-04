
#include <stdio.h>


int bubble_sort(int arr[], int size) {


    // [29, 10, 14, 37, 14]
    // Ultimate Objective - 
    // Maximum element to be pushed towards the end (right)

    // [10, 29, 14, 37, 14]
    // [10, 14, 29, 37, 14]
    // [10, 14, 29, 37, 14]
    // [10, 14, 29, 14, 37] - First Result

    // [10, 14, 14, 29, 37] - 2nd
    // [10, 14, 14, 29, 37] - 3rd // No swapping

    // Algo respects the fact the sequence is already sorted

    // Already Sorted Sequence - Best Case
    // O(n)

    // Worst Case - O(n^2)

    for (int i = 0; i < size - 1; i++) { // O(n)

        int swapped = 0;
        // Boolean flag that indicates whether swapping happened
        // in the current pass

        for (int j = 0; j < size - i - 1; j++) { // O(n)

            if (arr[j] > arr[j + 1]) {
                // Swapping Logic 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }

        }
        if (!swapped) { // if (swapped == 0)
            break;
        }
    }

    return 0;
}


int main() {

    int arr[] = {29, 10, 14, 37, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
