#include<stdio.h>

void pascal(int level, long long int tri[][100])
{
    int i,j;
    for(i=3; i<=level; i++)
    {
        for(j=1; j<=i; j++)
        {
            tri[i][j]=tri[i-1][j]+tri[i-1][j-1];
        }
    }
}

int main()
{
    int n;
    int i,j;
    long long int tri[100][100]={0,};
    scanf("%d",&n);
    tri[1][1]=1, tri[2][1]=1; tri[2][2]=1;
    pascal(n,tri);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%lld ",tri[i][j]);
        }
        printf("\n");
    }
}
