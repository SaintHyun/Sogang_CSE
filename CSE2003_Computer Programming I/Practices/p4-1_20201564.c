#include<stdio.h>

int main()
{
    int a,b,c,d;
    printf("����: ");
    scanf("%4d%2d%2d",&a,&b,&c);
    printf("����� ����: %d / %d / %d\n",a,b,c);
    printf("����: ");
    scanf("%d",&d);
    printf("2020�⿡ ����� %d��",a,b,c,d-a+1);
}
