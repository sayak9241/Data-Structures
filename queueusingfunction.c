#include <stdio.h>
#include <stdlib.h>
#define S 5

int f = -1, r = -1;

void enqueue(int no, int que[]){
    if (r == S-1)
        printf("Overflow");

    else if(f == -1 && r == -1){
        f = r = 0;
        que[r] = no;
    }

    else{
        r++;
        que[r] = no;
    }
}

void dequeue(int que[]){
    if (f == -1)
        printf("Underflow");

    else if (f == r){
        printf("%d is deleted",que[f]);
        f = -1;
        r = -1;
    }

    else{
        printf("%d is deleted",que[f]);
        f++;
    }
}

void display(int que[]){
    for (int i = f; i<=r; i++)
        printf("%d -> ",que[i]);
}

int main(){
    int ch,no,que[20];

    do{
        printf("\n1 for enqueue\n2 for dequeue\n3 for display\n4 for exit\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            printf("Enter a number : ");
            scanf("%d",&no);
            enqueue(no,que);
            break;

            case 2:
            dequeue(que);
            break;

            case 3:
            display(que);
            break;
        }
    }while(ch!=4);
}