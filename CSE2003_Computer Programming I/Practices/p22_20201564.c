#include<stdio.h>

int main()
{
    int a,b,sum=0,i;
    printf("Input first number: ");
    scanf("%d",&a);
    printf("Input second number: ");
    scanf("%d",&b);
    if(a<1 || b<1)
    {
        printf("Input is less than 1");
        return 0;
    }
    if(a>b)
    {
        int c;
        c=a; a=b; b=c;
    }
    for(i=a; i<=b; i++)
    {
        if(i%2==0 || i%3==0) sum+=i;
    }
    printf("Result: %d",sum);

}
