#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}queue_node;

typedef struct
{
    queue_node *front;
    int count;
    queue_node *rear;
}queue;

void Exit(queue *q)
{
    q->count=-5;
}
void Enqueue(queue *q)
{
    int data;
    printf("Input Data > ");
    scanf("%d",&data);
    queue_node *pNew;
    pNew=(queue_node*)malloc(sizeof(queue_node));
    pNew->data=data;
    pNew->next=NULL;
    if(q->count==0) q->front=pNew;
    else q->rear->next=pNew;
    (q->count)++;
    q->rear=pNew;
    return;
}
void PrintAll(queue q)
{
    if(q.front==NULL)
    {
        printf("EMPTY!\n");
        return;
    }
    while((q.front)!=NULL)
    {
        printf("%d ",(q.front)->data);
        q.front=(q.front)->next;
    }
    printf("\nQueue Level : %d\n",q.count);
    (q.count)=0;
}
void Dequeue(queue *q)
{
    if(q->count==0)
    {
        printf("EMPTY!\n");
        //free(del);
        return;
    }
    else if(q->count==1)
    {
        queue_node *del;
        del=q->front;
        printf("Dequeue %d\n",q->front->data);
        q->rear=NULL;
        q->front=NULL;
        (q->count)--;
        free(del);
    }
    else
    {
        queue_node *del;
        del=q->front;
        printf("Dequeue %d\n",q->front->data);
        q->front=q->front->next;
        (q->count)--;
        free(del);
    }
}

int main()
{
    printf("****** Menu ******\n");
    printf("*0 : Exit        *\n");
    printf("*1 : Enqueue     *\n");
    printf("*2 : Dequeue     *\n");
    printf("*3 : Print All   *\n");
    printf("******************\n");
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->count=0;
    q->rear=NULL;
    int a;
    do
    {
        printf("Select > ");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            Enqueue(q);
            break;
        case 2:
            Dequeue(q);
            break;
        case 3:
            PrintAll(*q);
            break;
        case 0:
            Exit(q);
            break;
        default:
            printf("Input Error! - Try Again!\n");

        }
    }while(q->count!=-5);
    free(q);
}
