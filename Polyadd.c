#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff;
    int pow;
    struct Node *next;
}node;

void createNode(int x,int y,node **tmp){
    node *r;
    if(*tmp==NULL){
        r = (node *)malloc(sizeof(node));
        r->coeff = x;
        r->pow = y;
        r->next = NULL;
        *tmp = r;    
    }

    else{
        createNode(x,y,(&(*tmp)->next));       
    }
}

void polyAdd(node *poly1,node *poly2,node **poly3){
    node *poly,*tmp;
    int p,c;
    while (poly1 != NULL && poly2 != NULL){
        poly = (node *)malloc(sizeof(node));
        if(poly1->pow>poly2->pow){
            p = poly1->pow;
            c = poly1->coeff;
            poly1 = poly1->next;
        }

        else if(poly2->pow>poly1->pow){
            p = poly2->pow;
            c = poly2->coeff;
            poly2 = poly2->next;
        }

        else{
            p = poly1->pow;
            c = poly1->coeff+poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        createNode(c,p,(&(*poly3)));
    }
    while(poly1!=NULL)
    {
        createNode(poly1->coeff,poly1->pow,(&(*poly3)));
        poly1=poly1->next;
    }
    while(poly2!=NULL)
    {
        createNode(poly2->coeff,poly2->pow,(&(*poly3)));
        poly2=poly2->next;
    }
}

void show(node *node){
    while(node!=NULL){
        printf("%dx^%d ",node->coeff,node->pow);
        node = node->next;
        printf("+ ");
    }
}

int main(){
    node *poly1 = NULL;node *poly2 = NULL;node *poly = NULL;
    createNode(5,12,&poly2);
    createNode(4,10,&poly2);
    createNode(9,6,&poly2);
    createNode(6,4,&poly2);
    createNode(3,2,&poly2);

    createNode(5,10,&poly1);
    createNode(8,6,&poly1);
    // createNode(4,4,&poly1);
    // createNode(5,2,&poly1);

    printf("First Input : \n");
    show(poly1);
    printf("\n\nSecond Input : \n");
    show(poly2);

    polyAdd(poly1,poly2,&poly);
    printf("\n\nAfter Addition : \n");
    show(poly);
}