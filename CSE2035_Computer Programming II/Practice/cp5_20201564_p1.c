#include<stdio.h>

void func(int arr[], int n, int psum[][1000])
{
    int i,j;
    for(i=0; i<n; i++)
    {
        psum[i][i]+=arr[i];
        for(j=i+1; j<n; j++)
        {
            psum[i][j]+=psum[i][j-1]+arr[j];
        }
    }
}

int main()
{
    int n,i;
    int arr[1000];
    int a,b;
    int psum[1000][1000]={0,}; // code block 에서는 안 되는데 cspro 서버에서는 main에 선언해도 되네.
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d%d",&a,&b);
    func(arr,n,psum);
    printf("%d",psum[a][b]);
}
