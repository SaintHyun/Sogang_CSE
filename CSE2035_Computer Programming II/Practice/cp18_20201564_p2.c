#include<stdio.h>
#include<stdlib.h>

typedef struct node *nptr;
typedef struct node
{
    char data;
    nptr link;
}NODE;

nptr head=NULL;

void InsertNodeAtFront(char a)
{
    NODE *pNew;
    pNew=(NODE*)malloc(sizeof(NODE));
    pNew->data=a;
    pNew->link=head;
    head=pNew;
}

void InsertNodeAtBack(char b)
{
    NODE *pNew;
    NODE *f=head;
    pNew=(NODE*)malloc(sizeof(NODE));
    while(1)
    {
        f=f->link;
        if(f->link==NULL) break;
    }
    pNew->data=b;
    pNew->link=NULL;
    f->link=pNew;
}

void PrintList()
{
    NODE *p=head;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->link;
    }
    printf("\n");
}

int main()
{
    InsertNodeAtFront('p');
    InsertNodeAtFront('p');
    InsertNodeAtFront('a');
    InsertNodeAtBack('l');
    InsertNodeAtBack('e');
    PrintList();

    return 0;
}
