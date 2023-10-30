#include<stdio.h>

void fourMath(int *c, int *d);
void printResult(int *c, int *d);

int a,b;

int main()
{
    int a,b;
    printf("Input two number : ");
    scanf("%d%d",&a,&b);
    fourMath(&a,&b);
}

void fourMath(int *c, int *d)
{
    a=*c+*d;
    b=*c-*d;
    printResult(&a,&b);
}

void printResult(int *c, int *d)
{
    printf("Result : a+b=%d, a-b=%d, a*b=%d, a/b=%d",*c,*d,((*c+*d)/2) * ((*c-*d)/2),((*c+*d)/2) / ((*c-*d)/2) );
}
