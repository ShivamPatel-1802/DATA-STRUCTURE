#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int ch;

    do {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 3);

    return 0;
}