#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* n(int val) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

int is_bst(struct node* node, int min, int max) {
    if (node == NULL) return 1;
    if (node->data < min || node->data > max) return 0;
    return is_bst(node->left, min, node->data - 1) &&
           is_bst(node->right, node->data + 1, max);
}

// Tehnica 2: Pre-order (Nod, Stanga, Dreapta)
void preOrderTraversal(struct node* node) {
    if (node != NULL) {
        printf("%d ", node->data); // Root e primul vizitat mereu [cite: 50]
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

int main() {
    struct node* root = n(10);
    root->left = n(5);
    root->right = n(15);

    printf("Parcurgere Pre-order: ");
    preOrderTraversal(root);
    printf("\n");

    if (is_bst(root, -1000, 1000)) printf("Este BST\n");
    else printf("NU este BST\n");

    return 0;
}