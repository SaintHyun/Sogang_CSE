#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,k=0;
    scanf("%d",&n);
    int **a;
    a=(int **)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        a[i]=(int *)malloc(sizeof(int)*n);
    }
    i=0; j=n/2;
    while(k<n*n)
    {
        k++;
        a[i][j]=k;
        if(k%n==0)
        {
            i++;
            continue;
        }
        i--; j++;
        if(i<0) i=n-1;
        else if(j>=n) j=0;
        if(k%n==0)
        {
            i++;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        free(a[i]);
    }
    free(a);
}
