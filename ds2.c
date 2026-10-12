#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

int push(int x)
{
    if (top == MAX - 1)
        return -1;
    stack[++top] = x;
    return 1;
}

int pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int peek()
{
    if (top == -1)
        return -1;
    return stack[top];
}

int display()
{
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    return 1;
}

int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    printf("Stack: ");
    display();

    printf("\nTop = %d", peek());
    printf("\nPopped = %d", pop());

    return 0;
}