#include<stdio.h>

void swap(float *x, float *y)
{
    float p;
    p=*x;
    *x=*y;
    *y=p;
}

int main()
{
    float x,y;
    printf("Input two Number");
    printf("\nx : ");
    scanf("%f",&x);
    printf("y : ");
    scanf("%f",&y);
    printf("-----------------------------\n");
    printf("Before : x [%g] y [%g]\n",x,y);
    swap(&x,&y);
    printf("-----------------------------\n");
    printf("After : x [%g] y [%g]",x,y);
}
