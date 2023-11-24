#include <stdio.h>
#include <stdlib.h>  // For malloc() and free()

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * @brief Recursively calculates the length of a linked list.
 * Calculates the length of a linked list.
 *
 * @param head The head node of the linked list.
 * @return The length of the linked list.
 */
int recLength(Node *head) {
    if (head == NULL) {
        return 0;
    } else {
        return 1 + recLength(head->next);
    }
}

/**
 * @brief Recursively finds a node with the specified data in a linked list.
 * Finds a node with the specified data in a linked list.
 *
 * @param head The head of the linked list.
 * @param data The data to search for.
 * @return A pointer to the node containing the data, or NULL if not found.
 */
Node *find(Node *head, int data) {
    if (head == NULL) {
        return NULL;
    } else if (head->data == data) {
        return head;
    } else {
        return find(head->next, data);
    }
}

/**
 * @brief Recursively finds the last node in a linked list.
 * Returns the last node in a linked list that contains the specified data.
 *
 * @param head The head node of the linked list.
 * @return The last node in the linked list that contains the specified data, or
 * NULL if not found.
 */
Node *last(Node *head) {
    // Check if the linked list is empty.
    if (head == NULL) {
        return NULL;
        // Check if the current node is the last node.
    } else if (head->next == NULL) {
        return head;
    } else {
        return last(head->next);
    }
}

/**
 * @brief Recursively inserts a node with the specified data into a linked list.
 * Appends a node with the specified data to the end of a linked list.
 *
 * @param head The head node of the linked list.
 * @param data The data to append.
 * @return The head node of the linked list.
 */
Node *append(Node *head, int data) {
    if (head == NULL) {
        // Allocate memory for the new node.
        Node *newNode = (Node *)malloc(sizeof(Node));

        // Initialize the new node.
        newNode->data = data;
        newNode->next = NULL;

        // Return the new node.
        return newNode;
    } else {
        head->next = append(head->next, data);

        // Return the head node of the linked list.
        return head;
    }
}

/**
 * @brief Recursively destroys a linked list by freeing each node.
 *
 * This function takes the head of a linked list as input and recursively
 * destroys the list by freeing each node. It returns NULL when the entire
 * list has been destroyed.
 *
 * @param head The head of the linked list.
 * @return Node* The updated head of the linked list (NULL when list is
 * destroyed).
 */
Node *destroy(Node *head) {
    if (head == NULL) {
        return NULL;
    } else {
        Node *next = head->next;
        free(head);
        return destroy(next);
    }
}

int main() {
    // Test for the functions
    Node *head = NULL;
    head = append(head, 1);

    printf("head->data = %d\n", head->data);
    printf("head->next = %p\n", (void *)head->next);

    head = append(head, 2);

    printf("head->data = %d\n", head->data);

    Node *lastNode = last(head);
    printf("lastNode->data = %d\n", lastNode->data);

    head = destroy(head);

    printf("head = %p\n", (void *)head);

    return 0;
}