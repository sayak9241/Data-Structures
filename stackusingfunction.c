#include <stdio.h>
#include <stdio.h>
#define S 5
    
int top=-1;
void push(int no,int stk[]){
    if (top==S-1)
        printf("Stack Overflow");
    else if (top==-1){
        top=0;
        stk[top]=no;

    }
    else{
        top++;
        stk[top]=no;
    }
}

void pop(int stk[]){
    if(top==-1)
        printf("Stack Underflow");
    else{
        printf("%d is deleted",stk[top]);
        top--;
    }
}

void display(int stk[]){
    for(int i=top;i>=0;i--){
        printf("%d -> ",stk[i]);
    }
}

int main(){
    int stk[20],top=-1,ch,no;
    // int ch,no;
    
    do{
        printf("\n1 for push \n2 for pop \n3 for display \n4 for exit\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:

            printf("Enter a number");
            scanf("%d",&no);
            push(no,stk);
            break;

            case 2:
            pop(stk);
            break;

            case 3:
            display(stk);
            break;
        }
    }while(ch!=4);

}