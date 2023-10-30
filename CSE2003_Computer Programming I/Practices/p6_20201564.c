#include<stdio.h>

int a,b;

int sum(int x,int y);

int main()
{
    printf("첫 번쨰 숫자 입력: ");
    scanf("%d",&a);
    printf("두 번쨰 숫자 입력: ");
    scanf("%d",&b);
    printf("%d + %d = %d",a,b,sum(a,b));
}

int sum(int x,int y)
{
    return x+y;
}
