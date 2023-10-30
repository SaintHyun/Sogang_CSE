#include<stdio.h>
#include<stdlib.h>

typedef struct node *nptr;
typedef struct node
{
    int data;
    struct node *link;
}NODE;

void Insert(NODE **head, int data)
{
    NODE *pNew=(NODE*)malloc(sizeof(NODE));
    NODE *f=(NODE*)malloc(sizeof(NODE));
    f=*head;
    if(*head==NULL)
    {
        *head=(NODE*)malloc(sizeof(NODE));
        (*head)->link=NULL;
        (*head)->data=data;
        return;
    }
    while(f->link!=NULL)
    {
        f=f->link;
    }
    pNew->data=data;
    pNew->link=NULL;
    f->link=pNew;
}

void Delete(NODE **head)
{
    NODE *p=(NODE*)malloc(sizeof(NODE));
    p=*head;
    (*head)=(*head)->link;
    free(p);
}

void PrintAll(NODE *head)
{
    NODE *p=head;
    if(head==NULL)
    {
        printf("Empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",(p)->data);
        (p)=(p)->link;
    }
    printf("\n");
}

int main()
{
    int A[10]={3,9,8,2,11,10,7,1,4,6};
    int i;
    nptr head=NULL;
    for(i=0; i<10; i++)
    {
        Insert(&head,A[i]);
    }
    PrintAll(head);
    for(i=0; i<10; i++)
    {
        Delete(&head);
        PrintAll(head);
    }
    free(head);
}
