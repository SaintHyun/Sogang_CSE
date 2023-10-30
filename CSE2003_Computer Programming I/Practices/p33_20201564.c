#include<stdio.h>

int n,m,A[21],cnt=0;

void q(int s, int i, int sum)
{
    printf("s=%d i=%d\n",s,i);
    if(s==n+1)
    {
        if(i!=0 && sum==m)
        {
            cnt++;
        }
        return;
    }
    q(s+1,i+1,sum+A[s]);
    q(s+1,i,sum);
}

int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&A[i]);
    }
    q(1,0,0);
    printf("The number of subsets is %d",cnt);
}
