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

int get_level(struct node* root, int val, int level) {
    if (root == NULL) return 0;
    if (root->data == val) return level;
    int l = get_level(root->left, val, level + 1);
    if (l != 0) return l;
    return get_level(root->right, val, level + 1);
}

int is_sibling(struct node* root, int a, int b) {
    if (root == NULL) return 0;
    if (root->left && root->right) {
        if ((root->left->data == a && root->right->data == b) ||
            (root->left->data == b && root->right->data == a)) return 1;
    }
    return is_sibling(root->left, a, b) || is_sibling(root->right, a, b);
}

void preOrderTraversal(struct node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

int main() {
    struct node* root = n(1);
    root->left = n(2); root->right = n(3);
    root->left->left = n(4); root->right->right = n(5);

    printf("Parcurgere Pre-order: ");
    preOrderTraversal(root);
    printf("\n");

    int lev4 = get_level(root, 4, 1);
    int lev5 = get_level(root, 5, 1);

    if (lev4 == lev5 && !is_sibling(root, 4, 5)) printf("Nodurile 4 si 5 sunt verisori\n");
    else printf("Nodurile 4 si 5 NU sunt verisori\n");

    return 0;
}