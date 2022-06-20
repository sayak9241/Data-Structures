#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void addbeg(node **,int);
void addbetween(node **,int,int);
void addend(node **,int);
void insertafter(node **,int,int);
void delbeg(node **);
void delpos(node **,int);
void delno(node **,int);
void delend(node **);
void display(node *);

void addbeg(node **head, int val)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = (*head);
    *head = ptr;
}

void addbetween(node **head, int val,int pos)
{
    node *tmp, *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    tmp = *head;
    for (int i=2;i<pos;i++){
        tmp = tmp->next;
    }
    ptr->next = tmp->next;
    tmp->next = ptr;
}

void addend(node **head, int val)
{
    node *tmp, *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    if (*head == NULL)
        *head = ptr;
    else{
        tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = ptr;
    }
}

void insertafter(node **head, int val,int afterno)
{
    node *tmp,*ptr;
    tmp = *head;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    while (tmp!=NULL){
        if (tmp->data == afterno)
            break;
        tmp = tmp->next;
    }
    ptr->next = tmp->next;
    tmp->next = ptr;
}

void delbeg(node **head)
{
    if (*head == NULL)
        return;
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp = (*head);
    (*head) = tmp->next;
    free(tmp);
}

void delpos(node **head,int pos){
    node *tmp,*ptr;
    tmp = *head;
    for(int i=2;i<pos;i++)
        tmp = tmp->next;
    ptr = tmp->next;
    tmp->next = ptr->next;
    free(ptr);
}

void delno(node **head,int no){
    node *tmp,*prev;
    tmp = *head;
    while (tmp!=NULL){
        if (tmp->data == no){
            prev->next = tmp->next; 
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void delend(node **head)
{
    node *tmp, *ptr;
    tmp = *head;
    ptr = (*head)->next;
    while (ptr->next != NULL)
    {
        tmp = tmp->next;
        ptr = ptr->next;
    }
    tmp->next = NULL;
    free(ptr);
}

void display(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    node *head;
    head = NULL;
    int ch, a,b,c;
    do
    {
        printf("\n1.ADD AT BEGINNING\n2.ADD AT IN BETWEEN\n3.ADD AT THE END\n4.ADD AFTER\n5.DELETE AT BEGINNING\n6.DELETE AT A GIVEN POSITION\n7.DELETE A GIVEN NUMBER\n8.DELETE AT END\n9.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter the number to be added\n");
            scanf("%d", &a);
            addbeg(&head, a);
            break;

            case 2:
            printf("Enter a number to be added\n");
            scanf("%d", &a);
            printf("Enter the position\n");
            scanf("%d",&b);
            addbetween(&head, a, b);
            break;

            case 3:
            printf("Enter a number to be added\n");
            scanf("%d", &a);
            addend(&head, a);
            break;

            case 4:
            printf("Enter a number to be added\n");
            scanf("%d", &a);
            printf("Enter the number after which you want to insert\n");
            scanf("%d",&c);
            insertafter(&head, a,c);
            break;

            case 5:
            delbeg(&head);
            break;

            case 6:
            printf("Enter the position to be deleted\n");
            scanf("%d",&b);
            delpos(&head,b);
            break;

            case 7:
            printf("Enter the number to be deleted\n");
            scanf("%d",&c);
            delno(&head,c);
            break;

            case 8:
            delend(&head);
            
        }

        printf("The linked list is : \n");
        display(head);
    }while (ch!=9);
}