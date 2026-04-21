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

int height(struct node* node) {
    if (node == NULL) return 0;
    int l = height(node->left);
    int r = height(node->right);
    return 1 + (l > r ? l : r);
}

int is_balanced(struct node* root) {
    if (root == NULL) return 1;
    int diff = height(root->left) - height(root->right);
    if (abs(diff) <= 1 && is_balanced(root->left) && is_balanced(root->right)) return 1;
    return 0;
}

void inOrderTraversal(struct node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->data); 
        inOrderTraversal(node->right);
    }
}

int main() {
    struct node* root = n(1);
    root->left = n(2);
    root->right = n(4);
    root->left->left = n(3);
    root->left->right = n(5);

    printf("Parcurgere In-order: ");
    inOrderTraversal(root);
    printf("\n");

    if (is_balanced(root)) printf("Arborele este echilibrat\n");
    else printf("Arborele nu este echilibrat\n");

    return 0;
}
