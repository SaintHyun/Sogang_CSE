#include<stdio.h>

float avg(int a, int b, int c, int d);
float de(float f, int n);

int main()
{
    int a,b,c,d;
    float f;
    printf("Enter the first number :");
    scanf("%d",&a);
    printf("Enter the second number :");
    scanf("%d",&b);
    printf("Enter the third number :");
    scanf("%d",&c);
    printf("Enter the fourth number :");
    scanf("%d",&d);
    printf("**********average is %5.2f************\n",f=avg(a,b,c,d));
    printf("first number : %11d -- deviation : %10.2f\n",a,de(f,a));
    printf("second number : %10d -- deviation : %10.2f\n",b,de(f,b));
    printf("third number : %11d -- deviation : %10.2f\n",c,de(f,c));
    printf("fourth number : %10d -- deviation : %10.2f\n",d,de(f,d));
}

float avg(int a, int b, int c, int d)
{
    return (float)(a+b+c+d)/4;
}

float de(float f, int n)
{
    return (float)(n-f);
}
