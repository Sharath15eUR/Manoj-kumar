#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data; 
    struct node* prev, *next; 
}; 

struct node* insertNode (int data) 
{ 
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = data; 
    newnode->prev = newnode->next = NULL; 
    return newnode; 
} 

void sortedInsert(struct node** head_ref, struct node* newnode) 
{ 

    struct node* current; 
    if (*head_ref == NULL){
        *head_ref = newnode; 
    } 
    else if ((*head_ref)->data >= newnode->data) { 
         newnode->next = *head_ref; 
         newnode->next->prev = newnode; 
        *head_ref = newnode; 
    } 
    else { 
        current = *head_ref; 
        while (current->next != NULL && current->next->data < newnode->data){
            current = current->next; 
        }
        newnode->next = current->next; 
        if (current->next != NULL) {
            newnode->next->prev = newnode; 
        }
        current->next = newnode; 
        newnode->prev = current;
    } 
} 

void show(struct node* head) 
{ 

    while (head != NULL) { 

        printf("%d",head->data);  
        printf(" ");

        head = head->next; 

    } 
} 

int main() 
{ 

    struct node* head = NULL; 
    struct node* new_node =insertNode(5); 
    int num;

    sortedInsert(&head, new_node); 

    new_node = insertNode(3); 

    sortedInsert(&head, new_node); 

    new_node = insertNode(10); 

    sortedInsert(&head, new_node); 

    new_node = insertNode(8); 

    sortedInsert(&head, new_node); 

    new_node = insertNode(12); 

    sortedInsert(&head, new_node); 
    
	printf("Doubly Linked List: \n") ;
    show(head);
    printf("\nEnter the element to be inserted in a doubly linked list: ");
    scanf("%d", &num);
    new_node = insertNode(num); 
    sortedInsert(&head, new_node);
    printf("Doubly Linked List: \n") ;
    show(head); 
    return 0;
}
