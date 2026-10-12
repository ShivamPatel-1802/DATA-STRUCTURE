#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int value) {
    struct Node *n = malloc(sizeof(struct Node));

    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    n->data = value;
    n->prev = n->next = NULL;

    return n;
}

int main() {
    struct Node *head = NULL, *temp, *n;
    int count, value, i;
    int choice, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        n = createNode(value);

        if (head == NULL) {
            head = temp = n;
        } else {
            temp->next = n;
            n->prev = temp;
            temp = n;
        }
    }

    while (1) {
        printf("\n DOUBLY LINKED LIST \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Program terminated.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);

            printf("Enter position: ");
            scanf("%d", &pos);

            if (pos < 1) {
                printf("Invalid position\n");
                continue;
            }

            n = createNode(value);

            if (pos == 1) {
                n->next = head;

                if (head != NULL)
                    head->prev = n;

                head = n;
            } else {
                temp = head;

                for (i = 1; i < pos - 1 && temp != NULL; i++)
                    temp = temp->next;

                if (temp == NULL) {
                    printf("Invalid position\n");
                    free(n);
                } else {
                    n->next = temp->next;
                    n->prev = temp;

                    if (temp->next != NULL)
                        temp->next->prev = n;

                    temp->next = n;
                }
            }
        }

        else if (choice == 2) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            if (pos < 1 || head == NULL) {
                printf("Invalid position or empty list\n");
            } else if (pos == 1) {
                temp = head;
                head = head->next;

                if (head != NULL)
                    head->prev = NULL;

                free(temp);
            } else {
                temp = head;

                for (i = 1; i < pos && temp != NULL; i++)
                    temp = temp->next;

                if (temp == NULL) {
                    printf("Invalid position\n");
                } else {
                    temp->prev->next = temp->next;

                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;

                    free(temp);
                }
            }
        }

        else {
            printf("Invalid choice\n");
        }

        printf("\nForward List: ");

        for (temp = head; temp != NULL; temp = temp->next)
            printf("%d <-> ", temp->data);

        printf("NULL\n");

        printf("Backward List: ");

        temp = head;

        if (temp != NULL) {
            while (temp->next != NULL)
                temp = temp->next;
        }

        for (; temp != NULL; temp = temp->prev)
            printf("%d <-> ", temp->data);

        printf("NULL\n");
    }

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
