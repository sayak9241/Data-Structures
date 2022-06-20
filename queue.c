#include<stdio.h>
#include<stdlib.h>

//macro definition
#define S 100
#define ITEM int

//structure definition
typedef struct
{
    ITEM arr[S];
    int front,rear;
}queue;

void init(queue*);
int isfull(queue*);
int isempty(queue*);
int enqueue(queue*, ITEM);
int dequeue(queue*);

//main function
int main()
{
    queue s;
    init(&s);
    int c,e,r;
    while(1)
    {
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.CHECK IF Queue IS EMPTY OR NOT");
        printf("\n4.CHECK IF Queue IS FULL OR NOT");
        printf("\n5.QUIT");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("\nEnter the element to be enqueued : ");
                scanf("%d", &e);
                if(enqueue(&s,e)==0)
                    printf("\nQueue OVERFLOW.\n");
                else
                    printf("\nSuccessfully enqueued.\n");
                break;
            case 2:
                if(dequeue(&s)==0)
                    printf("\nQueue UNDERFLOW.\n");
                else
                    printf("\nSuccessfully dequeued.\n");
                break;
            case 3:
                if(isempty(&s)==1)
                    printf("Queue is Empty.");
                else
                    printf("Queue is  Not Empty.");
                break;
            case 4:
                if(isfull(&s)==1)
                    printf("Queue is Full.");
                else
                    printf("Queue is  Not Full.");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid input.");
        }
    }
    return 0;
}

//initialising the queue
void init(queue *pts)
{
    pts->front = -1;
    pts->rear= -1;
}

//checking if queue is full or not
int isfull(queue *pts)
{
    if((pts->rear == S-1 && pts->front==0) || (pts->front == pts->rear+1))
        return 1;
    else    
        return 0;
}

//checking if queue is empty or not
int isempty(queue *pts)
{
    if(pts->front==-1)
        return 1;
    else 
        return 0;
}

//pushing an element from front of queue
int enqueue(queue *pts, ITEM data)
{
    if(isfull(pts)==1)
        return 0;
    else
    {
        if(pts->front==-1)
            pts->front=0;
        if(pts->rear==S-1)
            pts->rear= 0;
        else
            ++pts->rear;
        pts->arr[pts->rear]= data;      
    }
}

int dequeue(queue *pts)
{
    if(isempty(pts)==1)
        return 0;
    else
    {
        int temp= pts->arr[pts->front];
        if(pts->front==pts->rear)
            pts->front= pts->rear= 1;
        else if(pts->front=S-1)
            pts->front= 0;
        else
            pts->front++;
        return temp;
    }
}