
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *r, int x) {
    if (r == NULL) {
        r = malloc(sizeof(struct node));
        r->data = x;
        r->left = r->right = NULL;
    }
    else if (x < r->data)
        r->left = insert(r->left, x);
    else if (x > r->data)
        r->right = insert(r->right, x);
    return r;
}

void inorder(struct node *r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

int main() {
    struct node *root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
