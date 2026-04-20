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

// Functie pentru a transforma arborele in string (afisare recursiva)
void serialize(struct node* root) {
    if (root == NULL) {
        printf("# "); // Simbol pentru nod nul
        return;
    }
    printf("%d ", root->data);
    serialize(root->left);
    serialize(root->right);
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
    root->right = n(3);

    printf("Parcurgere In-order (afisare): ");
    inOrderTraversal(root);

    printf("\nArborele transformat in string: ");
    serialize(root);
    printf("\n");

    return 0;
}