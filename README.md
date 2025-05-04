# Notes on Sorting Algorithms

## **Selection Sort**

### Concept

* Repeatedly select the smallest (or largest) element from the unsorted portion and swap it with the first unsorted element.
* Not adaptive and not stable.
* Time Complexity: **O(n²)** (all cases), Space: **O(1)**

### Example

Unsorted Array: `[29, 10, 14, 37, 14]`

| Pass | Array State            | Action          |
| ---- | ---------------------- | --------------- |
| 1    | `[10, 29, 14, 37, 14]` | Swap 10 with 29 |
| 2    | `[10, 14, 29, 37, 14]` | Swap 14 with 29 |
| 3    | `[10, 14, 14, 37, 29]` | Swap 14 with 29 |
| 4    | `[10, 14, 14, 29, 37]` | Swap 29 with 37 |



---

## **Insertion Sort**

### Concept

* Build the sorted array one item at a time.
* Take each element and insert it into the correct position in the already sorted part.
* Best for nearly sorted arrays.
* Time Complexity: **O(n²)** worst/average, **O(n)** best, Space: **O(1)**

### Example

Unsorted Array: `[29, 10, 14, 37, 14]`

| Pass | Array State            | Action                      |
| ---- | ---------------------- | --------------------------- |
| 1    | `[10, 29, 14, 37, 14]` | Insert 10 before 29         |
| 2    | `[10, 14, 29, 37, 14]` | Insert 14 between 10 and 29 |
| 3    | `[10, 14, 29, 37, 14]` | Already in order            |
| 4    | `[10, 14, 14, 29, 37]` | Insert 14 between 14 and 29 |

---

## **Bubble Sort**

### Concept

* Repeatedly swap adjacent elements if they are in the wrong order.
* Push the largest unsorted element to the end in each pass.
* Stable but inefficient for large lists.

### Example
Unsorted Array: `[29, 10, 14, 37, 14]`

### Pass Table
In each pass, adjacent elements are compared and **swapped if out of order**, pushing the largest unsorted element to the end. The process is repeated for the remaining unsorted portion.


| Pass | Comparisons                        | Swaps Made          | Array After Pass       |
| ---- | ---------------------------------- | ------------------- | ---------------------- |
| 1    | (29>10), (29>14), (29<37), (37>14) | 29↔10, 29↔14, 37↔14 | `[10, 14, 29, 14, 37]` |
| 2    | (10<14), (14<29), (29>14)          | 29↔14               | `[10, 14, 14, 29, 37]` |
| 3    | (10<14), (14==14), (14<29)         | None                | `[10, 14, 14, 29, 37]` |
| 4    | (10<14), (14==14)                  | None                | `[10, 14, 14, 29, 37]` |

### Key Points

* Bubble Sort performs **at most (n-1) passes**.
* It can **terminate early** if no swaps are made in a pass (like in Pass 3 and 4 here).
* Hence, it is an **adaptive** algorithm.

---

## **Merge Sort**

### Concept

* Divide and conquer strategy.
* Recursively split the array into halves, sort and merge them.
* Very time-efficient for large datasets.

### Example (Step-wise)

Initial: `[38, 27, 43, 3, 9, 82, 10]`

Split:

* `[38, 27, 43]` and `[3, 9, 82, 10]`
* `[38] [27, 43]`, `[3, 9] [82, 10]`

Merge:

* `[27, 38, 43]` and `[3, 9, 10, 82]`
* Final merge: `[3, 9, 10, 27, 38, 43, 82]`

---

## **Quick Sort**

### Concept

* Divide and conquer algorithm.
* Select a pivot, partition the array such that elements less than pivot are on left, greater on right, then recursively sort them.
* Highly efficient for average cases.

### Example

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
