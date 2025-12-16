#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int item;
    struct node *right;
};

/* Create a new BST node */
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert into BST */
struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->item) {
        root->left = insert(root->left, value);
    } else if (value > root->item) {
        root->right = insert(root->right, value);
    }

    return root;
}

/* Inorder Traversal */
void inorder(struct node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->item);
    inorder(root->right);
}

/* Preorder Traversal */
void preorder(struct node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->item);
    preorder(root->left);
    preorder(root->right);
}

/* Postorder Traversal */
void postorder(struct node *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->item);
}

/* Display BST (Inorder) */
void display(struct node *root) {
    printf("BST Elements (Inorder): ");
    inorder(root);
    printf("\n");
}

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Display 6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            display(root);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
