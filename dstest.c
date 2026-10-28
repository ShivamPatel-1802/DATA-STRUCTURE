#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// here struct node is used to create a new node
struct Node* createNode(int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}

int main() {
    struct Node *head = NULL, *temp, *n;
    int value, choice;

    // here the printf is used to create the initial list
    printf("Enter value: ");
    scanf("%d", &value);

    n = createNode(value);
    head = n;

    // here choice 1 is insert 2 is delete 3 is exit
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Exit");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter value: ");
        scanf("%d", &value);
        n = createNode(value);

        // here the insert of the node will be at beginning
        n->next = head;
        head->prev = NULL; 
        head = n;
    }
    else if (choice == 2) {
        // here we will find a node to delete
        temp = head;
        head = temp->next;
        temp->next->prev = temp;  
        free(temp);
    }

    // here the node will be displyed in the forward 
    printf("Forward: ");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    //here we will free all the remaining nodes
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;  
}
