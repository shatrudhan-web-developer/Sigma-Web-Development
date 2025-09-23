#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

// Function to traverse the linked list
void traverse() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp;
    temp = start;
    printf("\nList elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert at the end of the linked list
void insertAtEnd() {
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;

    if (start == NULL) {
        start = temp;
        return;
    }

    trav = start;
    while (trav->next != NULL)
        trav = trav->next;

    trav->next = temp;
    temp->prev = trav;
}

// Function to insert at the front
void insertAtFront() {
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;

    if (start == NULL) {
        start = temp;
        return;
    }

    temp->next = start;
    start->prev = temp;
    start = temp;
}

// Function to insert at any specified position
void insertAtPosition() {
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter position: ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;

    if (start == NULL) {
        start = newnode;
        return;
    }

    temp = start;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

// Function to delete from the end
void deleteEnd() {
    struct node* temp;
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    if (start->next == NULL) {
        start = NULL;
    } else {
        temp->prev->next = NULL;
    }
    free(temp);
}

// Function to delete from any specified position
void deletePosition() {
    int pos, i = 1;
    struct node *temp, *position;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    temp = start;
    if (pos == 1) {
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
        return;
    }

    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    position = temp->next;
    if (position->next != NULL)
        position->next->prev = temp;
    temp->next = position->next;
    free(position);
}

// Driver Code
int main() {
    int choice;
    while (1) {
        printf("\n1 To see list\n");
        printf("2 For insertion at starting\n");
        printf("3 For insertion at end\n");
        printf("4 For insertion at any position\n");
        printf("5 For deletion of first element\n");
        printf("6 For deletion of last element\n");
        printf("7 For deletion of element at any position\n");
        printf("8 To exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: traverse(); break;
            case 2: insertAtFront(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: 
                if (start == NULL)
                    printf("\nList is empty\n");
                else {
                    struct node* temp = start;
                    start = start->next;
                    if (start != NULL) start->prev = NULL;
                    free(temp);
                }
                break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: exit(0); 
            default: printf("\nInvalid Choice\n");
        }
    }
    return 0;
}