#include<stdio.h>
#include<stdlib.h>

//macro definition
#define S 10
#define ITEM int

//structure definition
typedef struct
{
    ITEM arr[S];
    int tos;
}stack;

//initialising the stack
void init(stack *pts)
{
    pts->tos = -1;
}

//checking if stack is full or not
int isfull(stack s)
{
    if(s.tos==S-1)
        return 1;
    else    
        return 0;
}

//checking if stack is empty or not
int isempty(stack s)
{
    if(s.tos==-1)
        return 1;
    else 
        return 0;
}

//pushing an element on the top of stack
int push(stack *pts, ITEM data)
{
    if(isfull(*pts)==1)
        return 0;
    pts->tos++;
    pts->arr[pts->tos]=data;
    return 1;
}

//removing the topmost element
int pop(stack *pts)
{
    if(isempty(*pts)==1)
        return 0;
    return pts->arr[pts->tos--];
}

//returning the topmost element
int peek(stack *pts)
{
    if(isempty(*pts)==1)
        return 0;
    return pts->arr[pts->tos];
}

int main()
{
    stack s;
    init(&s);
    int c,e,r;
    while(1)
    {
        printf("\n1.PEEK");
        printf("\n2.PUSH");
        printf("\n3.POP");
        printf("\n4.CHECK IF STACK IS EMPTY OR NOT");
        printf("\n5.CHECK IF STACK IS FULL OR NOT");
        printf("\n6.QUIT");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                if(isempty(s)==1)
                {    
                    printf("\nThe stack is empty.\n");
                    break;
                }
                printf("\nTopmost element is : %d\n",peek(&s));
                break;
            case 2:
                printf("\nEnter the element to be pushed : ");
                scanf("%d", &e);
                if(push(&s,e)==0)
                    printf("\nStack OVERFLOW.\n");
                else
                    printf("\nSuccessfully pushed.\n");
                break;
            case 3:
                r= pop(&s);
                if(r == 0)
                    printf("Stack UNDERFLOW");
                else
                    printf("\nPopped element is : %d\n",r);
                break;
            case 4:
                if(isempty(s)==1)
                    printf("Stack is Empty.");
                else
                    printf("Stack is  Not Empty.");
                break;
            case 5:
                if(isfull(s)==1)
                    printf("Stack is Full.");
                else
                    printf("Stack is  Not Full.");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid input.");
        }
    }
    return 0;
}