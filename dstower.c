#include <stdio.h>

int hanoi(int n, int source, int auxiliary, int destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %d to %d\n", source, destination);
        return 1;
    }

    hanoi(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %d to %d\n", n, source, destination);

    hanoi(n - 1, auxiliary, source, destination);

    return 1;
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    hanoi(n, 1, 2, 3);

    return 0;
}