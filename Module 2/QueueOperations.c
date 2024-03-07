#include <stdio.h>
# define SIZE 100
void enqueue();
void dequeue();
void isEmpty();
void isFull();
void show();
void count();
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
main()
{
    int ch;
    while (1)
    {
    	printf("\n");
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
		printf("3.Check whether the Queue is Empty\n");        
		printf("4.Check whether the Queue is Full\n");        
       	printf("5.Display the Queue\n");
       	printf("6.Number of Queue Elements\n");
	    printf("7.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            	enqueue();
            	break;
            case 2:
            	dequeue();
            	break;
            case 3:
            	isEmpty();
            	break;
            case 4:
            	isFull();
            	break;
            case 5:
            	show();
            	break;
            case 6:
            	count();
            	break;
            case 7:
            	exit(0);
            default:
            	printf("Incorrect choice \n");
        } 
    } 
} 
 
void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1){
		printf("Overflow \n");
	}
       
    else
    {
        if (Front == - 1)
      
        Front = 0;
        printf("Enter the element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 

void isEmpty()
{
	if (Front == - 1 || Front > Rear)
    {
        printf("The Queue is Empty \n");
        return ;
    }
    else{
    	printf("The Queue is not Empty \n");
    	return;
	}
}

void isFull(){
	if (Rear == SIZE - 1){
		printf("The Queue is full \n");
		return;
	}
	else{
		printf("The Queue is not full \n");
		return;
	}
       
}
 
void show()
{
    int i;
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}

void count()
{
	int count = 0;
    int i;
    if (Front == - 1)
        printf("The Number of elements in the queue:%d\n",count);
    else
    {
        printf("Queue: \n");
        for (i = Front; i <= Rear; i++){
        	count+=1;
		}
            
        printf("The Number of elements in the queue:%d\n",count);
    }
}
