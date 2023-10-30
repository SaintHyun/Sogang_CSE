#include<stdio.h>

int main()
{
    int a,b;
    printf("input two integers : ");
    scanf("%d%d",&a,&b);
    printf("%d / %d is %d with a remainder of %d\n",a,b,a/b,a%b);
    return 0;
}
