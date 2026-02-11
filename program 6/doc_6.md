# Max Heap and Min Heap Construction

This program constructs both a Max Heap and a Min Heap from a given array of integers and displays the heap representations.

## Data Structures

The program uses arrays to represent binary heaps:

- **arr1[n]**: A dynamically sized integer array that stores elements arranged in Max Heap order, where each parent node is greater than or equal to its children.

- **arr2[n]**: A dynamically sized integer array that stores elements arranged in Min Heap order, where each parent node is less than or equal to its children.

- **n**: An integer variable representing the number of elements in the arrays.

### Heap Properties

Both heaps are complete binary trees represented as arrays with the following index relationships:
- For a node at index `i`:
  - Left child is at index `2*i + 1`
  - Right child is at index `2*i + 2`
  - Parent is at index `(i-1)/2`

In a **Max Heap**, the value of each node is greater than or equal to the values of its children, with the maximum element at the root.

In a **Min Heap**, the value of each node is less than or equal to the values of its children, with the minimum element at the root.

## Functions Implemented

### 1. `void swap(int *a, int *b)`
**Purpose**: Swaps the values of two integer variables.

This utility function takes two pointers to integers and exchanges their values using a temporary variable. It is used during heapify operations to rearrange elements in the array to maintain heap properties.

### 2. `void maxHeapify(int arr[], int n, int i)`
**Purpose**: Maintains the Max Heap property for a subtree rooted at index i.

This recursive function ensures that the subtree rooted at the given index satisfies the Max Heap property. It first identifies the largest element among the node, its left child, and its right child. If the largest element is not the current node, it swaps the current node with the largest child and recursively heapifies the affected subtree. The function checks array bounds to avoid accessing invalid indices. This process continues down the tree until the heap property is satisfied.

### 3. `void minHeapify(int arr[], int n, int i)`
**Purpose**: Maintains the Min Heap property for a subtree rooted at index i.

Similar to maxHeapify but works in the opposite direction, this recursive function ensures the Min Heap property is maintained. It identifies the smallest element among the node and its children. If the smallest element is not the current node, it swaps and recursively heapifies the affected subtree. This ensures that each parent is smaller than its children throughout the subtree.

### 4. `void buildMaxHeap(int arr[], int n)`
**Purpose**: Converts an unsorted array into a Max Heap.

This function builds a Max Heap from an unordered array by calling maxHeapify on all non-leaf nodes in bottom-up manner. It starts from the last non-leaf node (at index n/2 - 1) and moves upward to the root (index 0). By processing nodes from bottom to top, it ensures that when a node is heapified, its subtrees are already valid heaps. This approach has a time complexity of O(n).

### 5. `void buildMinHeap(int arr[], int n)`
**Purpose**: Converts an unsorted array into a Min Heap.

This function constructs a Min Heap using the same bottom-up approach as buildMaxHeap. It iterates from the last non-leaf node to the root, calling minHeapify on each node. This ensures the entire array satisfies the Min Heap property where the smallest element is at the root and each parent is smaller than its children.

### 6. `void printArray(int arr[], int n)`
**Purpose**: Displays all elements of an array.

This simple utility function iterates through the array and prints each element separated by a space, followed by a newline. It provides a readable output format for visualizing the heap structure as stored in the array.

## Organization of main() Method

The main function demonstrates heap construction through the following sequence:

1. **Input Collection**: The program prompts the user to enter the number of elements and stores it in variable n.

2. **Array Declaration**: Two integer arrays, arr1 and arr2, are declared with size n to hold the Max Heap and Min Heap respectively.

3. **Element Input**: The program prompts for elements and reads them one by one. Each element is stored in both arr1 and arr2, creating identical copies of the input array.

4. **Max Heap Construction**: The buildMaxHeap function is called on arr1 to rearrange its elements into Max Heap order.

5. **Min Heap Construction**: The buildMinHeap function is called on arr2 to rearrange its elements into Min Heap order.

6. **Display Results**: Both heaps are printed using the printArray function, showing how the same input data is organized differently in Max Heap and Min Heap formats.

7. **Program Termination**: Returns 0 to indicate successful execution.

## Sample Output

### Run 1: Standard Input
```
Enter number of elements: 6
Enter elements:
3 9 2 1 4 5

Max Heap:
9 4 5 1 3 2 
Min Heap:
1 3 2 9 4 5 
```

### Run 2: Already Sorted Array
```
Enter number of elements: 5
Enter elements:
1 2 3 4 5

Max Heap:
5 4 3 1 2 
Min Heap:
1 2 3 4 5 
```

### Run 3: Reverse Sorted Array
```
Enter number of elements: 5
Enter elements:
5 4 3 2 1

Max Heap:
5 4 3 2 1 
Min Heap:
1 2 3 5 4 
```

### Run 4: Duplicate Elements
```
Enter number of elements: 7
Enter elements:
8 3 5 3 8 1 5

Max Heap:
8 8 5 3 3 1 5 
Min Heap:
1 3 5 3 8 8 5 
```

### Heap Visualization for Run 1

**Max Heap (9 4 5 1 3 2):**
```
       9
      / \
     4   5
    / \ /
   1  3 2
```

**Min Heap (1 3 2 9 4 5):**
```
       1
      / \
     3   2
    / \ /
   9  4 5
```

### Explanation

The same input array `[3, 9, 2, 1, 4, 5]` produces two different heap structures:

- **Max Heap**: Largest element (9) is at the root, and every parent is greater than or equal to its children.
- **Min Heap**: Smallest element (1) is at the root, and every parent is less than or equal to its children.

Both representations maintain the complete binary tree property using array-based storage.
