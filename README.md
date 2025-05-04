# Notes on Sorting Algorithms

## Fundamental Concepts
### What is a _Stable Sorting_ Algorithm?
A stable sorting algorithm is one that preserves the relative order of records with equal keys (i.e., values).

In simple terms, if two elements A and B are equal and appear in that order in the original array, they will appear in the same order after sorting if the algorithm is stable.

### What is an _Adaptive Sorting_ Algorithm?
An adaptive sorting algorithm is one that takes advantage of existing order in the input data and performs faster when the data is already (or nearly) sorted. 

In simple terms, if the input is partially sorted, an adaptive sorting algorithm will sort it faster than its worst-case performance.

---

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

### Example - Recursive Passes and Partitions

```c
Initial Array: [35, 33, 42, 10, 14, 19, 27, 44]
```

Consider the **last element as the pivot**.


#### **Initial Call**: `quick_sort(arr, 0, 7)`

**Array**: `[35, 33, 42, 10, 14, 19, 27, 44]`
**Pivot** = 44

* All elements are `< 44` → No swaps until final pivot placement
* **Swap 44 with itself**
  * Array after pass: `[35, 33, 42, 10, 14, 19, 27, 44]`
  * Pivot placed at index **7**

**Next recursive calls**:

* `quick_sort(arr, 0, 6)`
* `quick_sort(arr, 8, 7)` ← skipped (base case)


#### **Recursive Call**: `quick_sort(arr, 0, 6)`

**Array**: `[35, 33, 42, 10, 14, 19, 27]`
**Pivot** = 27

##### Partitioning:

| Index | Value | Compare w/ Pivot (27) | Swap With    |
| ----- | ----- | --------------------- | ------------ |
| 0     | 35    | >                     | -            |
| 1     | 33    | >                     | -            |
| 2     | 42    | >                     | -            |
| 3     | 10    | <                     | Swap with 35 |
| 4     | 14    | <                     | Swap with 33 |
| 5     | 19    | <                     | Swap with 42 |

* i = 2 → Swap pivot (27) with arr\[3]

* Array after pass: `[10, 14, 19, 27, 33, 42, 35, 44]`
* Pivot placed at index **3**

**Next recursive calls**:

* `quick_sort(arr, 0, 2)`
* `quick_sort(arr, 4, 6)`


#### **Recursive Call**: `quick_sort(arr, 0, 2)`

**Array**: `[10, 14, 19]`
**Pivot** = 19

* All elements < pivot → Final swap with itself
  * Array unchanged: `[10, 14, 19]`
  * Pivot at index **2**

**Next recursive calls**:

* `quick_sort(arr, 0, 1)`
* `quick_sort(arr, 3, 2)` ← skipped


#### **Recursive Call**: `quick_sort(arr, 0, 1)`

**Array**: `[10, 14]`
**Pivot** = 14

* 10 < 14 → No swap, then pivot swaps with itself
  * `[10, 14]`
  * Pivot at index **1**

**Both recursive calls** on (0,0) and (2,1) → base cases


#### **Recursive Call**: `quick_sort(arr, 4, 6)`

**Array**: `[33, 42, 35]`
**Pivot** = 35

| Index | Value | Compare w/ 35 | Swap    |
| ----- | ----- | ------------- | ------- |
| 4     | 33    | <             | No swap |
| 5     | 42    | >             | No swap |

* i = 4 → Swap pivot (35) with arr\[5]

* Array becomes: `[10, 14, 19, 27, 33, 35, 42, 44]`
* Pivot at index **5**

**Next recursive calls**:

* `quick_sort(arr, 4, 4)` ← base case
* `quick_sort(arr, 6, 6)` ← base case


#### Final Sorted Array:

```c
[10, 14, 19, 27, 33, 35, 42, 44]
```

---

### Recursive Calls Summary

| Call Range | Pivot | Resulting Subarray |
| ---------- | ----- | ------------------ |
| (0, 7)     | 44    | Pivot at 7         |
| (0, 6)     | 27    | Pivot at 3         |
| (0, 2)     | 19    | Pivot at 2         |
| (0, 1)     | 14    | Pivot at 1         |
| (4, 6)     | 35    | Pivot at 5         |

---

### Key Points

* Quick Sort is **efficient** and performs **in-place sorting**.
* Depth of recursion depends on pivot selection.
* Time Complexity:

  * Best/Average: **O(n log n)**
  * Worst: **O(n²)** (when partition is highly unbalanced)


---

## Comparative Summary

| Algorithm      | Time Complexity (Best / Avg / Worst) | Space    | Stable | Adaptive |
| -------------- | ------------------------------------ | -------- | ------ | -------- |
| Selection Sort | O(n²) / O(n²) / O(n²)                | O(1)     | ✖      | ✖        |
| Insertion Sort | O(n) / O(n²) / O(n²)                 | O(1)     | ✔      | ✔        |
| Bubble Sort    | O(n) / O(n²) / O(n²)                 | O(1)     | ✔      | ✔        |
| Merge Sort     | O(n log n) / O(n log n) / O(n log n) | O(n)     | ✔      | ✖        |
| Quick Sort     | O(n log n) / O(n log n) / O(n²)      | O(log n) | ✖      | ✖        |
