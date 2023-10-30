#include<stdio.h>

void calc(int *a, int *b, char op)
{
    if(op=='+') *a=*a + *b;
    if(op=='-') *a=*a - *b;
    if(op=='*') *a=*a * *b;
    if(op=='/') *a=*a / *b;
}

int main()
{
    int a,b;
    char c;
    scanf("%c",&c);
    scanf("%d%d",&a,&b);
    calc(&a,&b,c);
    printf("result: %d",a);
}
