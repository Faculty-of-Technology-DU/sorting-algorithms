#include <stdio.h>

int heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }

    return 0;
}

int build_min_heap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return 0;
}

int heap_sort_min(int arr[], int n) {
    build_min_heap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        // Swap smallest (root) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Rebuild heap with remaining elements
        heapify(arr, i, 0);
    }

    // Reverse the array to get ascending order
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    return 0;
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    heap_sort_min(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

