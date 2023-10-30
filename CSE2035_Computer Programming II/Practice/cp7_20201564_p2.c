#include<stdio.h>
#include<stdlib.h>

void double_double(int **a, int *size)
{
    int i,j,tmp;
    *size*=2;
    (*a)=realloc(*a,*size*sizeof(int));
    for(i=0; i<*size/2; i++)
    {
        (*a)[i+*size/2]=(*a)[i]*2;
    }
    for(i=0; i<*size-1; i++)
    {
        for(j=i+1; j<*size; j++)
        {
            if((*a)[j]<(*a)[i])
            {
                tmp=(*a)[j]; (*a)[j]=(*a)[i]; (*a)[i]=tmp;
            }
        }
    }
}

int main()
{
    int n;
    int *a;
    int i,j;
    scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<3; i++)
    {
        double_double(&a,&n);
        for(j=0; j<n; j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
}
