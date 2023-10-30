#include<stdio.h>

int next(int *a, int n)
{
    int i=n-1,j=n-1;
    while(i>0 && *(a+i)<=*(a+i-1))
    {
        i--;
    }
    if(i<=0) return 0;
    while(*(a+i-1)>=*(a+j))
    {
        j--;
    }
    int t;
    t=*(a+i-1);
    *(a+i-1)=*(a+j);
    *(a+j)=t;
    j=n-1;
    while(i<j)
    {
        t=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=t;
        i++; j--;
    }
    return 1;
}

int main()
{
    int n, a[8],b[8];
    int i,j,k,c=1;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",(a+i));
        *(b+i)=i+1;
    }
    i=0;
    do
    {
        c=1;
        for(i=0; i<n; i++)
        {
            if(*(a+i)==*(b+i)) c=0;
        }
        if(c==1)
        {
            for(i=0; i<n; i++)
            {
                printf("%d ",*(b+i));
            }
            printf("\n");
        }
    }while(next(b,n));
}
