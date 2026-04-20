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

// oglinda
void mirror(struct node* r) {
    if (r == NULL) return;
    mirror(r->left);
    mirror(r->right);
    struct node* tmp = r->left;
    r->left = r->right;
    r->right = tmp;
}

//adunat
int sum_all(struct node* r) {
    if (r == NULL) return 0;
    return r->data + sum_all(r->left) + sum_all(r->right);
}

// adancime
int get_depth(struct node* r) {
    if (r == NULL) return 0;
    int l = get_depth(r->left);
    int d = get_depth(r->right);
    return 1 + (l > d ? l : d);
}

// verisori
int get_level(struct node* r, int val, int level) {
    if (r == NULL) return 0;
    if (r->data == val) return level;
    int l = get_level(r->left, val, level + 1);
    if (l != 0) return l;
    return get_level(r->right, val, level + 1);
}

int is_sibling(struct node* r, int a, int b) {
    if (r == NULL) return 0;
    if (r->left && r->right) {
        if ((r->left->data == a && r->right->data == b) ||
            (r->left->data == b && r->right->data == a)) return 1;
    }
    return is_sibling(r->left, a, b) || is_sibling(r->right, a, b);
}

//verisori
int are_cousins(struct node* root, int a, int b) {
    if (get_level(root, a, 1) == get_level(root, b, 1) && !is_sibling(root, a, b))
        return 1;
    return 0;
}

// travers
void in_order(struct node* r) { if(r){ in_order(r->left); printf("%d ", r->data); in_order(r->right); } }
void pre_order(struct node* r) { if(r){ printf("%d ", r->data); pre_order(r->left); pre_order(r->right); } }
void post_order(struct node* r) { if(r){ post_order(r->left); post_order(r->right); printf("%d ", r->data); } }

int main() {
    struct node* root = n(10);
    root->left = n(20);
    root->right = n(30);
    root->left->left = n(40);
    root->left->right = n(50);
    root->left->left->left = n(60);

    printf("In-Order: "); in_order(root); printf("\n");
    printf("Pre-Order: "); pre_order(root); printf("\n");
    printf("Post-Order: "); post_order(root); printf("\n");

    printf("Suma valorilor: %d\n", sum_all(root));
    printf("Adancime: %d\n", get_depth(root));

    if(are_cousins(root, 40, 50)) printf("40 si 50 sunt verisori: NU (sunt frati)\n");
    if(are_cousins(root, 60, 50)) printf("60 si 50 sunt verisori: NU (nivele diferite)\n");

    mirror(root);
    printf("Dupa oglindire : "); pre_order(root); printf("\n");

    return 0;
}