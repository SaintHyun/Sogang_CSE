#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long *pibo;
    //int size=51;
    int n,i;
    scanf("%d",&n);
    pibo=(long long *)malloc(sizeof(long long)*51);
    pibo[1]=1; pibo[2]=1;
    for(i=3; i<=n; i++)
    {
        pibo[i]=pibo[i-1]+pibo[i-2];
    }
    for(i=1; i<=n; i++)
    {
        printf("%lld ",pibo[i]);
    }
    free(pibo);
}
