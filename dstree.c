#include <stdio.h>

void inorder(int a[], int i) {
    if (i >= 7) return;
    inorder(a, 2*i+1);
    printf("%d ", a[i]);
    inorder(a, 2*i+2);
}

void preorder(int a[], int i) {
    if (i >= 7) return;
    printf("%d ", a[i]);
    preorder(a, 2*i+1);
    preorder(a, 2*i+2);
}

void postorder(int a[], int i) {
    if (i >= 7) return;
    postorder(a, 2*i+1);
    postorder(a, 2*i+2);
    printf("%d ", a[i]);
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};

    printf("Tree Structure:\n");
    printf("          80\n");
    printf("     70\n");
    printf("          60\n");
    printf("50\n");
    printf("          40\n");
    printf("     30\n");
    printf("          20\n");

    printf("\nInorder Traversal: ");
    inorder(a, 0);

    printf("\nPreorder Traversal: ");
    preorder(a, 0);

    printf("\nPostorder Traversal: ");
    postorder(a, 0);

    return 0;
}