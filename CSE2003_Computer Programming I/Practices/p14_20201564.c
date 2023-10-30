#include<stdio.h>

int main()
{
    int a;
    printf("Enter the year to be tested: ");
    scanf("%d",&a);
    if(a%400==0 || (a%100!=0 && a%4==0)) printf("It is a leap year.");
    else
    {
        printf("It is not a leap year.\n");
        if((a-a%4)%100==0) printf("%d is a leap year.",a-a%4-4);
        else printf("%d is a leap year.",a-a%4);
    }
}
