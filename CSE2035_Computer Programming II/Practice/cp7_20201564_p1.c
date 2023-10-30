#include<stdio.h>
#include<stdlib.h>

void push_back(int **a, int *size, int value)
{
    (*size)++;
    printf("size=%d\n",*size);
    *a=(int *)realloc(*a,(*size) * sizeof(int));
    (*a)[*size-1]=value;
    //printf("push succeeded\n");
}

void pop_back(int **a, int *size)
{
    (*a)[*size-1]=0;
    *size-=1;
    printf("size=%d\n",*size);
    *a=(int *)realloc(*a,(*size)*sizeof(int));
    //printf("pop succeeded\n");
}

double average(int *a, int size)
{
    int i;
    double sum=0;
    for(i=0; i<size; i++)
    {
        sum+=(double)a[i];
    }
    return (double)sum/size;
}

double variance(int *a, int size)
{
    int i;
    double sum=0,sqsum=0;
    for(i=0; i<size; i++)
    {
        sum+=(double)a[i];
        sqsum+=((double)a[i])*((double)a[i]);
    }
    return (double)sqsum/size - ((double)sum/size)*((double)sum/size);
}

int main()
{
    int n;
    int k,e,size=0;
    int *a;
    int i,j;
    a=(int *)calloc(1,sizeof(int));
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d",&e);
            push_back(&a,&size,e);
            for(j=0; j<size; j++)
            {
                printf("%d ",a[j]);
            }
            printf("\n%lf %lf\n",average(a,size),variance(a,size));
        }
        else
        {
            pop_back(&a,&size);
            for(j=0; j<size; j++)
            {
                printf("%d ",a[j]);
            }
            printf("\n%lf %lf\n",average(a,size),variance(a,size));
        }
    }
}
