#include <stdio.h>
#include <stdlib.h>  // For malloc and free

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

/**
 * @brief Creates a new node with the given data.
 *
 * @param data The data to be stored in the new node.
 * @return A pointer to the newly created node.
 */
Node *create(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/**
 * @brief Inserts a new node with the given data into the binary tree.
 *
 * @param root The root of the binary tree.
 * @param data The data to be inserted.
 * @return The updated root of the binary tree.
 */
Node *insert(Node *root, int data) {
  if (root == NULL) {
    return create(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

/**
 * @brief Finds a node with the given data in the binary tree.
 *
 * @param root The root of the binary tree.
 * @param data The data to be found.
 * @return A pointer to the node with the given data, or NULL if not found.
 */
Node *find(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return find(root->left, data);
  } else {
    return find(root->right, data);
  }
}

/**
 * @brief Finds the minimum value node in the binary tree.
 *
 * @param root The root of the binary tree.
 * @return A pointer to the node with the minimum value, or NULL if the tree is
 * empty.
 */
Node *findMin(Node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left != NULL) {
    return findMin(root->left);
  }
  return root;
}

/**
 * @brief Removes a node with the given data from the binary tree.
 *
 * @param root The root of the binary tree.
 * @param data The data to be removed.
 * @return The updated root of the binary tree.
 */
Node *removeNode(Node *root, int data) {
  if (root == NULL)
    return NULL;
  else if (root->data > data)
    root->left = removeNode(root->left, data);
  else if (root->data < data)
    root->right = removeNode(root->right, data);
  else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    } else if (root->left == NULL) {
      Node *temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      Node *temp = root;
      root = root->left;
      free(temp);
    } else {
      Node *temp = findMin(root->right);
      root->data = temp->data;
      root->right = removeNode(root->right, temp->data);
    }
  }
  return root;
}

/**
 * @brief Destroys the binary tree and frees the memory.
 *
 * @param root The root of the binary tree.
 * @return NULL.
 */
Node *destroy(Node *root) {
  if (root == NULL) {
    return NULL;
  }
  destroy(root->left);
  destroy(root->right);
  free(root);
  return NULL;
}

/**
 * @brief The main function.
 *
 * @return 0 on success.
 */
int main() {
  Node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 17);
  root = insert(root, 1);
  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 8);
  root = insert(root, 13);

  Node *temp = find(root, 7);
  if (temp != NULL) {
    printf("Found node: %d, in position #%p\n", temp->data, (void*)temp);
  }

  temp = find(root, 9);
  if (temp == NULL) {
    printf("Node %d not found.\n", 9);
  }

  root = destroy(root);

  return 0;
}