# Notes on Sorting Algorithms

## **Selection Sort**

### Concept:

* Repeatedly selects the smallest (or largest) element from the unsorted portion and swaps it with the first unsorted element.
* Not adaptive and not stable.
* Time Complexity: **O(n²)** (all cases), Space: **O(1)**

### Example:

Unsorted Array: `[29, 10, 14, 37, 14]`

| Pass | Array State            | Action          |
| ---- | ---------------------- | --------------- |
| 1    | `[10, 29, 14, 37, 14]` | Swap 10 with 29 |
| 2    | `[10, 14, 29, 37, 14]` | Swap 14 with 29 |
| 3    | `[10, 14, 14, 37, 29]` | Swap 14 with 29 |
| 4    | `[10, 14, 14, 29, 37]` | Swap 29 with 37 |

---

## **Insertion Sort**

### Concept:

* Builds the sorted array one item at a time.
* Takes each element and inserts it into the correct position in the already sorted part.
* Best for nearly sorted arrays.
* Time Complexity: **O(n²)** worst/average, **O(n)** best, Space: **O(1)**

### Example:

Unsorted Array: `[29, 10, 14, 37, 14]`

| Pass | Array State            | Action                      |
| ---- | ---------------------- | --------------------------- |
| 1    | `[10, 29, 14, 37, 14]` | Insert 10 before 29         |
| 2    | `[10, 14, 29, 37, 14]` | Insert 14 between 10 and 29 |
| 3    | `[10, 14, 29, 37, 14]` | Already in order            |
| 4    | `[10, 14, 14, 29, 37]` | Insert 14 between 14 and 29 |

---

## **Bubble Sort**

### Concept:

* Repeatedly swaps adjacent elements if they are in the wrong order.
* Pushes the largest unsorted element to the end in each pass.
* Stable but inefficient for large lists.

### Example:

Unsorted Array: `[29, 10, 14, 37, 14]`

| Pass | Array State            | Action            |
| ---- | ---------------------- | ----------------- |
| 1    | `[10, 14, 29, 14, 37]` | Swap 29↔10, 29↔14 |
| 2    | `[10, 14, 14, 29, 37]` | Swap 29↔14        |
| 3    | `[10, 14, 14, 29, 37]` | No changes        |
| 4    | `[10, 14, 14, 29, 37]` | Sorted            |

---

## **Merge Sort**

### Concept:

* Divide and conquer strategy.
* Recursively splits the array into halves, sorts and merges them.
* Very efficient for large datasets.

### Example (Step-wise):

Initial: `[38, 27, 43, 3, 9, 82, 10]`

Split:

* `[38, 27, 43]` and `[3, 9, 82, 10]`
* `[38] [27, 43]`, `[3, 9] [82, 10]`

Merge:

* `[27, 38, 43]` and `[3, 9, 10, 82]`
* Final merge: `[3, 9, 10, 27, 38, 43, 82]`

---

## **Quick Sort**

### Concept:

* Divide and conquer algorithm.
* Selects a pivot, partitions the array such that elements less than pivot are on left, greater on right, then recursively sorts them.
* Highly efficient for average cases.

### Example:

Unsorted: `[29, 10, 14, 37, 14]`, Pivot = 14

Partition → `[10, 14, 14] [29, 37]`

Sorted result: `[10, 14, 14, 29, 37]`

---

## Comparative Summary

| Algorithm      | Time Complexity (Best / Avg / Worst) | Space    | Stable | Adaptive |
| -------------- | ------------------------------------ | -------- | ------ | -------- |
| Selection Sort | O(n²) / O(n²) / O(n²)                | O(1)     | ✖      | ✖        |
| Insertion Sort | O(n) / O(n²) / O(n²)                 | O(1)     | ✔      | ✔        |
| Bubble Sort    | O(n) / O(n²) / O(n²)                 | O(1)     | ✔      | ✔        |
| Merge Sort     | O(n log n) / O(n log n) / O(n log n) | O(n)     | ✔      | ✖        |
| Quick Sort     | O(n log n) / O(n log n) / O(n²)      | O(log n) | ✖      | ✖        |
