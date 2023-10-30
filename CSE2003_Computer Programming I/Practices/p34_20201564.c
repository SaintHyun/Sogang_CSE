#include<stdio.h>

int main()
{
    int n,i=1,j=1,k,cnt=0,po=0;
    int B[4][2]={{1,0},{0,1},{-1,-0},{0,-1}};
    int A[21][21]={0,};
    scanf("%d",&n);
    cnt=1;
    po=0;
    i=0; j=1;
    while(cnt<=n*n)
    {
        if(A[i+B[po%4][0]][j+B[po%4][1]]!=0 || (i+B[po%4][0]>n || j+B[po%4][1]>n) || (i+B[po%4][0]<1 || j+B[po%4][1]<1))
        {
            po++;
        }
        if(A[i+B[po%4][0]][j+B[po%4][1]]==0)
        {
            i+=B[po%4][0];
            j+=B[po%4][1];
            A[i][j]=cnt;
        }
        cnt++;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%-4d",A[i][j]);
            A[i][j]=0;
        }
        printf("\n");
    }
    printf("\n");
}

