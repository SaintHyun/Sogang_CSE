#include<stdio.h>

void divideRemainder(int *a, int *b);

int main()
{
    int a,b;
    printf("Input two numbers : ");
    scanf("%d%d",&a,&b);
    divideRemainder(&a,&b);
    printf("---------------------------------------------------\n");
    printf("OUTPUT : divide [%d] remainder [%d]",a,b);
}

void divideRemainder(int *a, int *b)
{
    int c;
    c=*a / *b;
    *b=*a % *b;
    *a=c;
}
