#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

struct Node* insertBeginning(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    return head;
}

struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void displayForward(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Forward: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    do
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertBeginning(head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 3:
                displayForward(head);
                break;

            case 4:
                displayBackward(head);
                break;

            case 5:
                freeList(head);
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}