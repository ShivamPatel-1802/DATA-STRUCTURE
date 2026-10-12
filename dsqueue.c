#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

/* Enqueue */
int enqueue(int item, int size)
{
    if (rear == size - 1)
    {
        printf("Queue Overflow\n");
        return 0;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;

    return 1;
}

/* Dequeue */
int dequeue()
{
    int item;

    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return 0;
    }

    item = queue[front];
    front++;

    if (front > rear)
        front = rear = -1;

    printf("Deleted element = %d\n", item);

    return 1;
}

/* Display Queue */
int display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return 0;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");

    return 1;
}

/* Insert at Front - Deque */
int insertFront(int item, int size)
{
    int i;

    if (front == 0)
    {
        printf("Cannot insert at Front\n");
        return 0;
    }

    if (front == -1)
    {
        front = rear = 0;
        queue[front] = item;
    }
    else
    {
        front--;

        for (i = rear; i >= front + 1; i--)
            queue[i] = queue[i - 1];

        queue[front] = item;
    }

    return 1;
}

/* Insert at Rear - Deque */
int insertRear(int item, int size)
{
    return enqueue(item, size);
}

/* Delete from Front - Deque */
int deleteFront()
{
    return dequeue();
}

/* Delete from Rear - Deque */
int deleteRear()
{
    int item;

    if (front == -1)
    {
        printf("Deque Underflow\n");
        return 0;
    }

    item = queue[rear];
    rear--;

    if (rear < front)
        front = rear = -1;

    printf("Deleted element = %d\n", item);

    return 1;
}

int main()
{
    int size, n, item, choice, i;

    printf("Enter size of Queue: ");
    scanf("%d", &size);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > size)
    {
        printf("Number of elements cannot be greater than size.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        enqueue(item, size);
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Insert Front (Deque)\n");
        printf("5. Insert Rear (Deque)\n");
        printf("6. Delete Front (Deque)\n");
        printf("7. Delete Rear (Deque)\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueue(item, size);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &item);
                insertFront(item, size);
                break;

            case 5:
                printf("Enter element: ");
                scanf("%d", &item);
                insertRear(item, size);
                break;

            case 6:
                deleteFront();
                break;

            case 7:
                deleteRear();
                break;

            case 8:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}