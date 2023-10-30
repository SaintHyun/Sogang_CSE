#include<stdio.h>

int main()
{
    int n,i=1,j=1,k,cnt=0,po=0;
    int B[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int A[21][21]={0,};
    scanf("%d",&n);
    for(k=n; k>=1; k--)
    {
        cnt=1;
        po=0;
        i=1; j=0;
        while(cnt<=k*k)
        {
            if(A[i+B[po%4][0]][j+B[po%4][1]]!=0 || (i+B[po%4][0]>k || j+B[po%4][1]>k) || (i+B[po%4][0]<1 || j+B[po%4][1]<1))
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
        for(i=1; i<=k; i++)
        {
            for(j=1; j<=k; j++)
            {
                printf("%4d",A[i][j]);
                A[i][j]=0;
            }
            printf("\n");
        }
        printf("\n");
    }
}
