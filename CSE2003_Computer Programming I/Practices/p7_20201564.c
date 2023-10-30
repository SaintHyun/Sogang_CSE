#include<stdio.h>

float x(int a, int b, int c, int d);
float y(float x, int a, int b);

int main()
{
    float rx;
    int a,b,c,d;
    printf("1st equation: y=ax-b, input 'a' and 'b'\na=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("2nd equation: y=cx-d, input 'c' and 'd'\nc=");
    scanf("%d%",&c);
    printf("d=");
    scanf("%d",&d);
    printf("result: \n");
    printf("x is %f\n",rx=x(a,b,c,d));
    printf("y is %f",y(rx,a,b));

}

float x(int a, int b, int c, int d)
{
    return (float)((b-d)/(a-c));
}

float y(float x, int a, int b)
{
    return (float)(a*x-b);
}
