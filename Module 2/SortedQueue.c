#include <stdio.h>
#define MAX_SIZE 100 

int queue[MAX_SIZE]; 
int front = -1, back = -1;

void enqueue(int item) {
    if (back == MAX_SIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1) { 
        front = 0; 
    }
    back++; 
    queue[back] = item;
}


int dequeue() {
    if (front == -1 || front > back) { 
        printf("Error: Queue is empty\n");
        return -1; 
    }
    int item = queue[front]; 
    front++; 
    return item;
}


void display() {
	int i;
    if (front == -1) { 
        printf("Error: Queue is empty\n");
        return;
    }
    for (i = front; i <= back; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void sort_queue() {
    int i, j, temp;
    int n = back - front + 1; 

    for (i = 0; i < n - 1; i++) { 
        for (j = i + 1; j < n; j++) { 
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

int main() {

    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(5);
    enqueue(1);

    printf("\nElements of the queue:\n");
    display();

    printf("\nSorted queue:");
    sort_queue();
    display();
    return 0;
}

