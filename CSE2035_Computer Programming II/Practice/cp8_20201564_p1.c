#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m,n,i,j;
    scanf("%d%d",&n,&m);
    int **a;
    a=(int **)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        a[i]=(int *)malloc(sizeof(int)*m);
    }

    for(i=0; i<n; i++)
    {
        a[i][0]=1;
    }
    for(i=0; i<m; i++)
    {
        a[0][i]=1;
    }

    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++)
    {
        free(a[i]);
    }
    free(a);
}
