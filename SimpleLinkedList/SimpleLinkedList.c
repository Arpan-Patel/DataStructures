#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void InsertNode(struct node **headref, int val) {
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    curr->val = val;
    curr->next = (*headref);
    (*headref) = curr;
}

void DisplayList(struct node *headref) {
    struct node *temp = NULL;
    int i = 0;

    for (temp = headref; temp != NULL; temp = temp->next) {
        printf("LL %d - %d\n", i++, temp->val);
        
    }
}

/* Adds Node at Tail */
void AppendToList(struct node **headref, int val) {
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *lastNode = *headref;
    
    curr->val = val;
    curr->next = NULL;
    
    if (curr == NULL) {
        (*headref) = curr;
    } else {
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = curr;
    }
}

/*
 * TODO: Check Whether headref is NULL or not
 */
void AppendAtPosition(struct node **headref, int findValue, int newValue) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *curr = NULL;
    int i = 0;

    for (curr = (*headref); curr->val != findValue; curr = curr->next) {
        printf(" LL %d - %d\n", i++, curr->val);
    }

    newNode->val = newValue;
    newNode->next = curr->next;
    curr->next = newNode;
}

void DeleteNode(struct node **headref, int Value) {
    struct node *curr = (*headref);
    struct node *prev = NULL;
    int i = 0;

    if (curr == NULL)
        printf("List Empty\n");


    prev = NULL;
    curr = (*headref);
    
    if (curr->next == NULL) {
        printf("Only one node, i.e. Head\n");
        if (curr->val == Value) {
            free(curr);
            printf("List Emptied\n");
        } else {
            printf("Node Not Found\n");
            return;
        }
    }

    curr = curr->next;
    if (curr->val == Value) {
       prev->next = curr->next;
       free(curr);
    }

    for (curr = (*headref), prev = curr; curr->val != Value; prev = curr, curr = curr->next) {
        printf("#LL %d - %d\n", i++, curr->val);
    }
    
    prev->next = curr->next;
    free(curr);
    printf("Node Deleted\n");


}

int main() {
    printf("Single Linked List\n");

    int i = 0;
    struct node *head = NULL;
    struct node *temp = NULL;
    InsertNode(&head, 1);
    InsertNode(&head, 0);
    InsertNode(&head, 3);
    AppendToList(&head, 8);
    AppendToList(&head, 9);
    AppendAtPosition(&head, 8, 7);

    DisplayList(head);

    DeleteNode(&head, 1);
    DisplayList(head);


    return 0;
}
