#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st{
    struct st *next;
    struct st *prev;
    char *data;
}node;

node *createnode(char *val){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = strdup(val);
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

node *searchbyposition(node *head,int pos){
    int i=1,count=1;
    node *tmp = head;
    if(head == NULL)
        return NULL;

    while(head->next != NULL){
        head = head->next;
        count++;
    }

    if(pos>count || pos<=0){
        printf("\nInvalid Position\n");
        return NULL;
    }

    for(i = 1; i < pos; i++)
        tmp = tmp->next;

    return tmp;
}

void play(node *pos){
    printf("%s",pos->data);
}

void addbegin(node *head,int pos,char *val,FILE *fp){
    node *tmp, *nodepos = NULL;
    tmp = createnode(val);
    nodepos = searchbyposition(head,pos);

    tmp->prev = nodepos->prev;
    tmp->next = nodepos;
    nodepos->prev->next = tmp;
    nodepos->prev = tmp;

    fp = fopen("music.txt","w");
    while(head != NULL){
        fprintf(fp,"%s",head->data);
        head = head->next;
    }
}

void addafter(node *head,int pos,char *val,FILE *fp){
    node *tmp, *nodepos = NULL;
    tmp = createnode(val);
    nodepos = searchbyposition(head,pos);

    tmp->prev = nodepos;
    tmp->next = nodepos->next;
    nodepos->next->prev = tmp;
    nodepos->next = tmp;

    fp = fopen("music.txt","w");
    while(head != NULL){
        fprintf(fp,"%s",head->data);
        head = head->next;
    }
}

void addend(node **head,node **tail,char *val){
    node *tmp = createnode(val);
    if(*head == NULL){
        *head = tmp;
        *tail = tmp;
        return;
    }

    tmp->prev = *tail;
    (*tail)->next = tmp;
    *tail = tmp;
}

void delete(node *head,int pos){
    node *posnode = NULL;
    posnode = searchbyposition(head,pos);
    node *tmp = posnode->next;

    tmp->next = posnode->next;
    posnode->next->prev = tmp;
}

void traverse(node *head){
    while (head != NULL){
        printf("%s",head->data);
        head = head->next;
    }
}

int main(){
    FILE *fp;int p;
    char c,t[40], dump;
    char str[40];
    node *head = NULL, *tail = NULL, *pos = NULL, *curr;
    fp = fopen("music.txt", "r");
    while ((fgets(str, 40, fp)))
        addend(&head, &tail, str);
    traverse(head);
    do
    {
        printf("\nS start the player.");
        printf("\nJ jump to a specific track.");
        printf("\nN next track.");
        printf("\nP previous track.");
        printf("\nF first track.");
        printf("\nL last track.");
        printf("\nA add a track after an existing track.");
        printf("\nB add a track before an existing track.");
        printf("\n R remove a specific track from the list.");
        printf("\n T to print the playlist.");

        printf("\nEnter your choice: ");
        scanf("%c%c", &c, &dump);

        switch (c)
        {
        case 'S':
            curr = head;
            play(curr);
            break;
        case 'J':
            printf("\nEnter a position: ");
            scanf("%d", &p);
            pos = searchbyposition(head, p);
            play(pos);
            break;
        case 'N':
            if (curr->next == NULL)
            {
                curr = head;
                play(curr);
            }
            else
            {
                play(curr->next);
                curr = curr->next;
            }
            break;

        case 'P':
            if (curr->prev == NULL)
                break;
            else
            {
                play(curr->prev);
                curr = curr->prev;
            }
            break;

        case 'F':
            play(head);
            break;

        case 'L':
            play(tail);
            break;

        case 'A':
            printf("\nEnter a pos: ");
            scanf("%d%c", &p, &dump);
            printf("\nEnter a track: ");
            fgets(t, sizeof(t), stdin);
            addafter(head, p, t, fp);
            break;
        case 'B':
            printf("\nEnter a pos: ");
            scanf("%d%c", &p, &dump);
            printf("\nEnter a track: ");
            fgets(t, sizeof(t), stdin);
            addbegin(head, p, t, fp);
            break;

        case 'R':
            printf("\nEnter a pos: ");
            scanf("%d", &p);
            delete (head, p);
            break;

        case 'T':
            traverse(head);
            break;

        case 'Y':
            continue;

        case 'n':
            return 0;

        default:
            break;
        }
        printf("\nDo you want to continue? ");
        scanf("%c", &c);
    } while (c != 'n');

    fclose(fp);

    return 0;
}