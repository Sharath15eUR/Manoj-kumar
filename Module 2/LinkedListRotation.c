#include <stdio.h>  
#include <stdlib.h>
   
struct node{  
    char data;  
    struct node *previous;  
    struct node *next;  
};      
   
int size = 0;    
struct node *head, *tail = NULL;  
   
void addNode(char data) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
    }  
    else {  
        tail->next = newNode;  
        newNode->previous = tail;  
        tail = newNode;  
        tail->next = NULL;  
    }  
    size++;  
}  
   
void rotateList(int n) {  
    struct node *current = head;
	int i;
      
    if(n == 0 || n >= size) {
	    return;  
	}  
    
    else {  
        for(i = 1; i < n; i++)   
            current = current->next;  
          
        tail->next = head;  
        head = current->next;  
        head->previous = NULL;  
        tail = current;  
        tail->next = NULL;  
    }  
}  
   
void display() {  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        printf("%c ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
   
int main()  
{  
    addNode('a');
    addNode('b');  
    addNode('c');  
    addNode('d');  
    addNode('e');  
    int N;
	printf("Enter the number of rotation:");
	scanf("%d",&N);
    printf("Original List: \n");  
    display();  
    
    rotateList(N);  
      
    printf("Updated List: \n");  
    display();  
   
    return 0;  
}  
