#include <stdio.h>
#include <stdlib.h>

// Definition of doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node after a given node
void insertAfter(struct Node* givenNode, int value) {
    if (givenNode == NULL) {
        printf("Given node cannot be NULL\n");
        return;
    }

    struct Node* newNode = createNode(value);

    newNode->next = givenNode->next;
    newNode->prev = givenNode;

    if (givenNode->next != NULL)
        givenNode->next->prev = newNode;

    givenNode->next = newNode;
}

// Delete a given node
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL)
        return;

    // If node to be deleted is head
    if (*head == delNode)
        *head = delNode->next;

    // Change next only if node to be deleted is not last
    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    // Change prev only if node to be deleted is not first
    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
}

// Display the list forward
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Creating initial list: 10 <-> 20 <-> 30
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Initial Doubly Linked List:\n");
    display(head);

    // Insert after second node
    insertAfter(second, 25);
    printf("\nAfter inserting 25 after 20:\n");
    display(head);

    // Delete second node (20)
    deleteNode(&head, second);
    printf("\nAfter deleting node with data 20:\n");
    display(head);

    return 0;
}
