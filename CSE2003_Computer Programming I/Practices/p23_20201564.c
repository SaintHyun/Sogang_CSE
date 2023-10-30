#include<stdio.h>

void func_gcd(int a, int b, int *gcd)
{
    if(a%b==0)
    {
        *gcd=b;
        return;
    }
    func_gcd(b,a%b,gcd);
}

int main()
{
    int a,b,gcd=1;
    printf("Input first number: ");
    scanf("%d",&a);
    printf("Input second number: ");
    scanf("%d",&b);
    func_gcd(a,b,&gcd);
    printf("GCD: %d",gcd);
}
