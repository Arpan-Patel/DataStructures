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

    DisplayList(head);

    return 0;
}
