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

struct node* find_lca(struct node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct node* left = find_lca(root->left, n1, n2);
    struct node* right = find_lca(root->right, n1, n2);

    if (left != NULL && right != NULL) return root;
    return (left != NULL) ? left : right;
}


void postOrderTraversal(struct node* node) {
    if (node != NULL) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data); 
    }
}

int main() {
    struct node* root = n(1);
    root->left = n(2);
    root->right = n(3);
    root->left->left = n(4);
    root->left->right = n(5);

    printf("Parcurgere Post-order: ");
    postOrderTraversal(root);
    printf("\n");

    struct node* lca = find_lca(root, 4, 5);
    if (lca != NULL) printf("Cel mai apropiat stramos comun pentru 4 si 5 este: %d\n", lca->data);

    return 0;
}
