#include<stdio.h>

int main()
{
    int a;
    printf("Input: ");
    scanf("%d",&a);
    printf("%d is %s number.",a, a%2==0 ? "even" : "odd");
}
