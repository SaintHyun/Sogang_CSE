#include<stdio.h>

int isDivisor(int m, int n)
{
    if(n%m==0) return 1;
    else return 0;
}
int isPrime(int m)
{
    int i;
    for(i=2; i*i<=m; i++)
    {
        if(m%i==0) return 0;
    }
    return 1;
}

int main()
{
    int a,i;
    printf("Input : ");
    scanf("%d",&a);
    for(i=2; i<=a; i++)
    {
        if(isDivisor(i, a))
        {
            if(isPrime(i)) printf("%d\t",i);
        }
    }
}
