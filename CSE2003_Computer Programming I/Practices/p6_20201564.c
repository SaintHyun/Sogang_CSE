#include<stdio.h>

int a,b;

int sum(int x,int y);

int main()
{
    printf("ù ���� ���� �Է�: ");
    scanf("%d",&a);
    printf("�� ���� ���� �Է�: ");
    scanf("%d",&b);
    printf("%d + %d = %d",a,b,sum(a,b));
}

int sum(int x,int y)
{
    return x+y;
}
