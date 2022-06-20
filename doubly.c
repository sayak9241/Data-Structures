#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}node;

node *createNode(int val){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->prev = NULL;
    tmp->next = NULL;
    tmp->data = val;
    return tmp;
}

void addbegin(node **head,node **tail,int val){
    node *tmp = createNode(val);
    if (*head == NULL){
        *head = tmp;
        *tail = tmp;
    }
    (*head)->prev = tmp;
    tmp->next = *head;
    *head = tmp;
}

void append(node **head,node **tail,int val){
    node *tmp = createNode(val);
    if (*tail == NULL){
        *head = tmp;
        *tail = tmp;
    }
    (*tail)->next = tmp;
    tmp->prev = *tail;
    *tail = tmp;

}

void delbegin(node **head){
    node *tmp = *head;
    if (tmp == NULL)
        return;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(tmp);
}

void delend(node **tail){
    node *tmp = *tail;
    if (tmp == NULL)
        return;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(tmp);
}

node *searchbyposition(node *head,int pos){
    int count = 1;
    node *tmp;
    if (head == NULL){
        printf("Invalid input");
        return NULL;
    }

    if (pos<=0){
        printf("Invalid input");
        return NULL;
    }

    while (head->next!=NULL){
        head = head->next;
        count++;
    }

    if (pos>count){
        printf("Invalid input");
        return NULL;
    }
    head = tmp;
    for (int i=1;i<pos;i++){
        head = head->next;
    }
    return head;
}

void traversingforward(node* head)
{
    while(head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
}
void traversingbackward(node* tail)
{
    while(tail != NULL)
    {
        printf("%d->",tail->data);
        tail = tail->prev;
    }
}

int main()
{
    node *head,*tail;
    head = NULL;
    tail = NULL;
    int ch, a,p;
    do
    {
        printf("\n1.ADD AT BEGINNING\n2.ADD AT THE END\n3.DELETE AT BEGINNING\n4.DELETE AT END\n5.SEARCH A GIVEN POSITION\n6.EXIT\n");
        printf("Enter your choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter the number to be added\n");
            scanf("%d", &a);
            addbegin(&head,&tail, a);
            break;

            case 2:
            printf("Enter a number to be added\n");
            scanf("%d", &a);
            append(&head,&tail, a);
            break;

            case 3:
            delbegin(&head);
            break;

            case 4:
            delend(&tail);
            break;

            case 5:
            printf("Enter the position\n");
            scanf("%d",&p);
            searchbyposition(head,p);
            
        }

        printf("The linked list is : \n");
        traversingforward(head);
        traversingbackward(tail);
    }while (ch!=6);
}