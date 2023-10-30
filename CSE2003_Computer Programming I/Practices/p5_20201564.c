#include<stdio.h>

int a;

int sqr(int x);
int printOne(int y);

int main()
{
    printf("숫자 입력: ");
    scanf("%d",&a);
    sqr(a);
}

int printOne(int y)
{
    printf("결과: %d",y);
}

int sqr(int x)ZOQ
{
    x=x*x;
    printOne(x);
}
