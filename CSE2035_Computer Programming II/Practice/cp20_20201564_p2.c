#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char command[10];
    struct node *next;
}queue_node;

typedef struct
{
    queue_node *front;
    int count;
    queue_node *rear;
}queue;

int CheckCommand(char *command)
{
    char A[10][10]={{"help"},{"dir"},{"mkdir"},{"cd"},{"history"},{"h"},{"quit"},{"q"}};
    int i,l=0;
    for(i=0; i<8; i++)
    {
        if(!strcmp(A[i],command)) l=1;
    }
    return l;
}

void EnqueueCommand(queue *pQueue, char *dataIn)
{
    queue_node *pNew;
    pNew=(queue_node*)malloc(sizeof(queue_node));
    strcpy(pNew->command,dataIn);
    pNew->next=NULL;
    if(pQueue->count==0) pQueue->front=pNew;
    else (pQueue->rear)->next=pNew;
    (pQueue->count)++;
    pQueue->rear=pNew;
    return;
}

int DequeuePrint(queue *pQueue, char *dataOut)
{
    if(pQueue->count==0)
    {
        return 0;
    }
    else if(pQueue->count==1)
    {
        queue_node *del;
        del=pQueue->front;
        strcpy(dataOut,pQueue->front->command);
        pQueue->rear=NULL;
        pQueue->front=NULL;
        (pQueue->count)--;
        free(del);
    }
    else
    {
        queue_node *del;
        del=pQueue->front;
        strcpy(dataOut,pQueue->front->command);
        pQueue->front=pQueue->front->next;
        (pQueue->count)--;
        free(del);
    }
}

int main()
{
    char command[10];
    queue *pQueue;
    pQueue=(queue*)malloc(sizeof(queue));
    pQueue->front=NULL;
    pQueue->count=0;
    pQueue->rear=NULL;
    int l,a=1;
    while(1)
    {
        printf(">>");
        scanf("%s",command);
        l=CheckCommand(command);
        if(l==1 && strcmp(command,"history") && strcmp(command,"h") && strcmp(command,"quit") && strcmp(command,"q"))
        {
            printf("[Valid] %s\n",command);
            EnqueueCommand(pQueue,command);
        }
        else if(l==0)
        {
            printf("[Invalid]\n");
        }
        else if(l==1 && (!strcmp(command,"history") || !strcmp(command,"h")))
        {
            while(a!=0)
            {
                a=DequeuePrint(pQueue,command);
                printf("%s\n",command);
            }
        }
        else if(l==1 && (!strcmp(command,"quit") || !strcmp(command,"q")))
        {
            free(pQueue);
            return 0;
        }
    }
}
