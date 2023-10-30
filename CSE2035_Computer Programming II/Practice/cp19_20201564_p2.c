#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node *nptr;

typedef struct
{
    int count;
    struct node *top;
}stack;

typedef struct node
{
    char data;
    nptr link;
}stack_node;

void Push(stack *pstack, char b)
{
    stack_node *pNew=(stack_node*)malloc(sizeof(stack_node));
    pNew->data=b;
    pNew->link=pstack->top;
    pstack->top=pNew;
    pstack->count++;
}

int Pop(stack *pstack, char b)
{
    stack_node *f=(stack_node*)malloc(sizeof(stack_node));
    if(pstack->top)
    {
        if(b==pstack->top->data)
        {
            f=pstack->top;
            pstack->top=(pstack->top)->link;
            pstack->count--;
            free(f);
            return 1;
        }
        else if(b!=pstack->top->data)
        {
            free(f);
            return 0;
        }
    }
    else return 0;
}

int main()
{
    char a[110];
    stack *pstack=(stack*)malloc(sizeof(stack));
    pstack->top=NULL;
    pstack->count=0;
    scanf("%s",a);
    int len,i,how;
    len=strlen(a);
    for(i=0; i<len; i++)
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[') Push(pstack,a[i]);
        else if(a[i]==')')
        {
            how=Pop(pstack,a[i]-1);
            if(!how)
            {
                printf("Unmatched Parentheses!\n");
                return 0;
            }
        }
        else if(a[i]=='}'||a[i]==']')
        {
            how=Pop(pstack,a[i]-2);
            if(!how)
            {
                printf("Unmatched Parentheses!\n");
                return 0;
            }
        }
    }
    if(pstack->top!=NULL) printf("Unmatched Parentheses!\n");
    else printf("Matched Parentheses!\n");
    return 0;
}

