#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float coef;
    int expon;
}poly;

poly *poly_integral(int n, poly *a)
{
    poly *b;
    b=(poly*)calloc(n+2,sizeof(poly));
    int i;
    for(i=1; i<=n; i++)
    {
        b[i].expon=a[i].expon+1;
        b[i].coef=a[i].coef/(a[i].expon+1);
    }
    return b;
}

poly *poly_derivative(int n, poly *a)
{
    poly *c;
    int i;
    c=(poly*)calloc(n+1,sizeof(poly));
    //printf("enter derive %d\n",n);
    for(i=1; i<=n; i++)
    {
        c[i].expon=a[i].expon-1;
        c[i].coef=(a[i].expon)*a[i].coef;
        //printf("\n%d %d\n",c[i].coef, c[i].expon);
    }
    return c;
}

int main()
{
    poly *a;
    poly *b;
    poly *c;

    int n;
    scanf("%d",&n);
    a=(poly*)calloc(n+1,sizeof(poly));
    b=(poly*)calloc(n+2,sizeof(poly));
    c=(poly*)calloc(n+1,sizeof(poly));
    int i;
    for(i=1; i<=n; i++)
    {
        scanf("%f%d",&a[i].coef,&a[i].expon);
    }
    b=poly_integral(n,a);
    c=poly_derivative(n,a);
    printf("Integral:1.00");
    for(i=1; i<=n; i++)
    {
        if(b[i].coef>0) printf("+%.2fx^%d",b[i].coef,b[i].expon);
        else if(b[i].coef<0) printf("%.2fx^%d",b[i].coef,b[i].expon);
    }
    printf("\n");
    i=2;
    printf("Derivative:");;
    if(c[1].expon!=-1)
    {
        if(c[1].coef!=0 && c[1].expon==0) printf("%.2f",c[1].coef);
        else if(c[1].coef!=0 && c[1].expon!=0) printf("%.2fx^%d",c[1].coef,c[1].expon);
    }
    else if(c[1].expon==-1 && c[2].coef!=0 && c[2].expon==0){ printf("%.2f",c[2].coef); c[2].coef=0;}
    else if(c[1].expon==-1 && c[2].coef>0 && c[2].expon!=0){ printf("%.2fx^%d",c[2].coef,c[2].expon); c[2].coef=0;}
    for(i=2; i<=n; i++)
    {
        if(c[i].coef>0) printf("+%.2fx^%d",c[i].coef,c[i].expon);
        else if(c[i].coef<0) printf("%.2fx^%d",c[i].coef,c[i].expon);
    }
}
