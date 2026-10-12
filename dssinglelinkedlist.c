#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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
    newNode->next = NULL;

    return newNode;
}

struct Node* insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
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
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 3:
                display(head);
                break;

            case 4:
                freeList(head);
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}