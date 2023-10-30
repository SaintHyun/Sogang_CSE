#include<stdio.h>

int main()
{
    int a,b,c,d;
    printf("생일: ");
    scanf("%4d%2d%2d",&a,&b,&c);
    printf("당신의 생일: %d / %d / %d\n",a,b,c);
    printf("연도: ");
    scanf("%d",&d);
    printf("2020년에 당신은 %d살",a,b,c,d-a+1);
}
