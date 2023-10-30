#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;
typedef NODE *nptr;

void Insert(nptr *head, int data)
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
void Sort(nptr *head)
{
    NODE *i,*j;
    int t;
    for(i=*head; i->link!=NULL; i=i->link)
    {
        for(j=i->link; j!=NULL; j=j->link)
        {
            if(i->data>j->data)
            {
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
}
void PrintAll(nptr *head)
{
    NODE *p=*head;
    while(p!=NULL)
    {
        printf("%d ",(p)->data);
        (p)=(p)->link;
    }
    printf("\n");
}

int main()
{
    int A[10]={3,9,8,2,5,10,7,1,4,6};
    int i;
    nptr head=NULL;
    for(i=0; i<10; i++)
    {
        Insert(&head,A[i]);
    }
    PrintAll(&head);
    Sort(&head);
    PrintAll(&head);
}
