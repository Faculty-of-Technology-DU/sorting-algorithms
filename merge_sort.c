
#include <stdio.h>

int merge(int arr[], int left, int mid, int right) {

    // Merge Sort needs additional space O(n) where n = n1 + n2
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_arr[n1], right_arr[n2];

    // Initial Population of Left Sub-array
    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[left + i];
    }

    // Initial Population of Right Sub-array
    for (int i = 0; i < n2; i++) {
        right_arr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    // i -> left_sub_array
    // j -> right_sub_array
    // k -> the index of the element in the final sorted array (arr)

    // Comparing and Combining left and right sub arrays
    while (i < n1 && j < n2) {

        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }

    // arr = [], left_sa (i) = [1, 2, 4, 5], right_sa (j) = [3, 9, 10, 11, 12]
    
    // arr = [1, 2, 3, 4, 5], left_sa = [], right_sa = [9, 10, 11, 12]

    // right_sa is already sorted

    // all elements of right_sa are definitely greater than
    // all elements of left_sa

    // Copy all remaining elements from right_sa to the final arr
    // [1, 2, 3, 4, 5, 9, 10, 11, 12]

    // remainder elements in left sub-array
    while (i < n1) {
        arr[k++] = left_arr[i++];
    }

    // remainder elements in right sub-array
    while (j < n2) {
        arr[k++] = right_arr[j++];
    }

    return 0;
}

int merge_sort(int arr[], int left, int right) {

    // For a single element array, (left == right) is true
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Calculation of mid index for division of array
        
        // Expansion of the Division Tree Recursively
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
        // key operation of comparing and merging sub-arrays 


    }
    return 0;
}

int main() {

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
