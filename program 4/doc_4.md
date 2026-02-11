# Doubly Linked List with Insertion and Deletion

This program implements a doubly linked list with operations to insert a node after a given position and delete a specified node from the list.

## Data Structures

The program uses a structure to represent nodes in a doubly linked list:

### `struct Node`
- **data**: An integer field that stores the value of the node.
- **prev**: A pointer to the previous node in the doubly linked list. For the first node, this pointer is NULL.
- **next**: A pointer to the next node in the doubly linked list. For the last node, this pointer is NULL.

Unlike a singly linked list, a doubly linked list allows traversal in both forward and backward directions because each node maintains pointers to both its predecessor and successor. The list is accessed through a head pointer pointing to the first node.

## Functions Implemented

### 1. `struct Node* createNode(int value)`
**Purpose**: Creates and initializes a new node with the given value.

This function dynamically allocates memory for a new node using `malloc()`. It sets the data field to the provided value and initializes both the prev and next pointers to NULL, indicating that the node is not yet connected to any other nodes. The function returns a pointer to the newly created node.

### 2. `void insertAfter(struct Node* givenNode, int value)`
**Purpose**: Inserts a new node immediately after a specified node.

This function takes a pointer to an existing node and a value for the new node. First, it validates that the given node is not NULL. Then it creates a new node and adjusts four pointers to maintain the doubly linked structure: the new node's next points to the given node's next, the new node's prev points to the given node, the given node's next is updated to point to the new node, and if there was a node after the given node, its prev pointer is updated to point to the new node. This ensures the bidirectional links are properly maintained.

### 3. `void deleteNode(struct Node** head, struct Node* delNode)`
**Purpose**: Deletes a specified node from the doubly linked list.

This function takes a double pointer to the head and a pointer to the node to be deleted. It handles several cases: if the list is empty or the node to delete is NULL, it returns immediately. If the node to delete is the head, it updates the head pointer to point to the next node. The function then updates the pointers of neighboring nodes to bypass the deleted node - if there's a next node, its prev pointer is updated, and if there's a previous node, its next pointer is updated. Finally, it frees the memory occupied by the deleted node using `free()`.

### 4. `void display(struct Node* head)`
**Purpose**: Displays all elements of the doubly linked list in forward order.

This function traverses the list from the head to the end using a temporary pointer. For each node, it prints the data value followed by " <-> " to visually represent the bidirectional links. After reaching the last node, it prints "NULL" to indicate the end of the list. This provides a clear visualization of the list structure.

## Organization of main() Method

The main function demonstrates the doubly linked list operations through the following sequence:

1. **List Creation**: Three nodes are created manually with values 10, 20, and 30 using the `createNode()` function.

2. **Manual Linking**: The nodes are linked together bidirectionally by setting their next and prev pointers. Node 10 links to node 20, which links to node 30, forming the initial list: 10 <-> 20 <-> 30.

3. **Initial Display**: The `display()` function is called to show the initial state of the doubly linked list.

4. **Insertion Operation**: The `insertAfter()` function is called to insert a new node with value 25 after the second node (containing 20). The updated list is then displayed.

5. **Deletion Operation**: The `deleteNode()` function is called to remove the node containing value 20 from the list. The final state of the list is displayed.

6. **Program Termination**: Returns 0 to indicate successful execution.

## Sample Output

### Complete Run
```
Initial Doubly Linked List:
10 <-> 20 <-> 30 <-> NULL

After inserting 25 after 20:
10 <-> 20 <-> 25 <-> 30 <-> NULL

After deleting node with data 20:
10 <-> 25 <-> 30 <-> NULL
```

### Explanation of Operations

**Initial State**: The list contains three nodes linked bidirectionally: 10 <-> 20 <-> 30

**After Insertion**: When 25 is inserted after node 20, it is placed between 20 and 30, resulting in: 10 <-> 20 <-> 25 <-> 30. The bidirectional pointers are adjusted so that 20's next points to 25, 25's prev points to 20, 25's next points to 30, and 30's prev points to 25.

**After Deletion**: When the node containing 20 is deleted, nodes 10 and 25 are directly linked together, bypassing the deleted node: 10 <-> 25 <-> 30. The memory for node 20 is freed.

### Edge Case Scenarios
```
// Deleting head node
Initial: 10 <-> 20 <-> 30
After deleting head: 20 <-> 30

// Deleting last node
Initial: 10 <-> 20 <-> 30
After deleting last: 10 <-> 20

// Inserting after last node
Initial: 10 <-> 20 <-> 30
After inserting 40 after 30: 10 <-> 20 <-> 30 <-> 40
```
