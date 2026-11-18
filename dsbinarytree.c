
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

// Recursive Traversals
void inorder(struct Node *r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct Node *r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct Node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

// Non-Recursive Inorder
void inStack(struct Node *r) {
    struct Node *s[100], *p = r;
    int t = -1;

    while (p || t != -1) {
        while (p) {
            s[++t] = p;
            p = p->left;
        }
        p = s[t--];
        printf("%d ", p->data);
        p = p->right;
    }
}

// Non-Recursive Preorder
void preStack(struct Node *r) {
    struct Node *s[100], *p;
    int t = -1;

    if (!r) return;
    s[++t] = r;

    while (t != -1) {
        p = s[t--];
        printf("%d ", p->data);

        if (p->right) s[++t] = p->right;
        if (p->left) s[++t] = p->left;
    }
}

// Non-Recursive Postorder
void postStack(struct Node *r) {
    struct Node *s1[100], *s2[100], *p;
    int t1 = -1, t2 = -1;

    if (!r) return;
    s1[++t1] = r;

    while (t1 != -1) {
        p = s1[t1--];
        s2[++t2] = p;

        if (p->left) s1[++t1] = p->left;
        if (p->right) s1[++t1] = p->right;
    }

    while (t2 != -1)
        printf("%d ", s2[t2--]->data);
}

int main() {
    struct Node *root = create(1);

    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);

    printf("\nRecursive Traversals:\n");
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

    printf("\n\nNon-Recursive Traversals:\n");
    printf("Inorder: ");
    inStack(root);
    printf("\nPreorder: ");
    preStack(root);
    printf("\nPostorder: ");
    postStack(root);

    return 0;
}
