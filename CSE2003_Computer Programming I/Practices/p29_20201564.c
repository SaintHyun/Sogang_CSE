#include<stdio.h>

float avg(int A[][101], int i, int n)
{
    int j,cnt=0;
    for(j=1; j<=n; j++)
    {
        cnt+=A[j][i];
    }
    return (float)cnt/n;
}

int main()
{
    const int m=101;
    int A[101][101];
    int n,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1; i<=n; i++)
    {
        printf("%.2f ",avg(A,i,n));
    }
}
