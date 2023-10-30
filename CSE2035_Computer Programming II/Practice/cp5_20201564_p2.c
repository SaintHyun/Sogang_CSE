#include<stdio.h>

int min(int res[][1000], int i, int j)
{
    if(res[i+1][j]==0) return res[i+1][j+1];
    if(res[i+1][j+1]==0) return res[i+1][j];
    if(res[i+1][j]<res[i+1][j+1]) return res[i+1][j];
    return res[i+1][j+1];
}

void func(int arr[], int n, int res[][1000])
{
    int i,j;
    for(i=n-2; i>=0; i--)
    {
        for(j=0; j<n; j++)
        {
            res[i][j]=min(res,i,j);
        }
    }
}

int main()
{
    int n,i,j;
    int arr[1000],res[1000][1000]={0,};
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        res[n-1][i]=arr[i];
    }
    func(arr,n,res);
    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
}
