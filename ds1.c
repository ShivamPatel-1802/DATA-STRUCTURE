#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int A[10][10], B[10][10];
    int i, j, k;

    // Input dimensions
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Validate dimensions
    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
        printf("Invalid matrix dimensions!\n");
        return 0;
    }

    // Input Matrix A
    printf("\nEnter elements of Matrix A:\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input Matrix B
    printf("\nEnter elements of Matrix B:\n");
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Addition and Subtraction
    if(r1 == r2 && c1 == c2) {
        printf("\nAddition (A + B):\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++)
                printf("%d ", A[i][j] + B[i][j]);
            printf("\n");
        }

        printf("\nSubtraction (A - B):\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++)
                printf("%d ", A[i][j] - B[i][j]);
            printf("\n");
        }
    } else {
        printf("\nAddition and Subtraction are not possible.\n");
    }

    // Multiplication A × B
    if(c1 == r2) {
        int AB[10][10];

        printf("\nMultiplication (A x B):\n");

        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                AB[i][j] = 0;
                for(k = 0; k < c1; k++)
                    AB[i][j] += A[i][k] * B[k][j];
                printf("%d ", AB[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nA x B is not possible.\n");
    }

    // Multiplication B × A
    if(c2 == r1) {
        int BA[10][10];

        printf("\nMultiplication (B x A):\n");

        for(i = 0; i < r2; i++) {
            for(j = 0; j < c1; j++) {
                BA[i][j] = 0;
                for(k = 0; k < c2; k++)
                    BA[i][j] += B[i][k] * A[k][j];
                printf("%d ", BA[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nB x A is not possible.\n");
    }

    return 0;
}