#include<stdio.h>

int q(int *n)
{
    return *n%10;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    do
    {
        printf("%d",q(&n));
        n/=10;
    } while(n>=1);
}
