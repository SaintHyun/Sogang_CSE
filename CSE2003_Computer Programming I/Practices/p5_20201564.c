#include<stdio.h>

int a;

int sqr(int x);
int printOne(int y);

int main()
{
    printf("���� �Է�: ");
    scanf("%d",&a);
    sqr(a);
}

int printOne(int y)
{
    printf("���: %d",y);
}

int sqr(int x)ZOQ
{
    x=x*x;
    printOne(x);
}
