#include<stdio.h>

int main(void)
{
    int a;
    printf("input a: ");
    scanf("%d",&a);
    printf("a=%d\n",a);
    printf("a=a+1 : %d\n",++a);
    printf("a=a+1 : %d\n",++a);
    printf("a=a-1 : %d\n",--a);
    return 0;
}
