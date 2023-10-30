#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    int numerator;
    int denominator;
}FRACTION;

void getFr(FRACTION *pFr)
{
    printf("Write a fraction in the form of x/y: ");
    scanf("%d/%d",&(*pFr).numerator,&(*pFr).denominator);
}

void printFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes, char op)
{
    printf("\nThe result of %d/%d %c %d/%d is %d/%d\n",(*pFr1).numerator,(*pFr1).denominator,op,(*pFr2).numerator,(*pFr2).denominator,(*pRes).numerator,(*pRes).denominator);
}

int gcd(int a, int b)
{
    if(a==0 || b==0) return 1;
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    return a;
}

void addFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes)
{
    int a1,b1,a2,b2,g;
    a1=(*pFr1).numerator; b1=(*pFr1).denominator;
    a2=(*pFr2).numerator; b2=(*pFr2).denominator;
    (*pRes).numerator=a1*b2+a2*b1;
    (*pRes).denominator=b1*b2;
    g=gcd((*pRes).numerator,(*pRes).denominator);
    (*pRes).numerator/=g;
    (*pRes).denominator/=g;
    if((*pRes).numerator==0) (*pRes).denominator=1;
    if((*pRes).denominator==0) (*pRes).numerator=1;
    printFr(pFr1,pFr2,pRes,'+');
}

void subFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes)
{
    int a1,b1,a2,b2,g;
    a1=(*pFr1).numerator; b1=(*pFr1).denominator;
    a2=(*pFr2).numerator; b2=(*pFr2).denominator;
    (*pRes).numerator=a1*b2-a2*b1;
    (*pRes).denominator=b1*b2;
    g=gcd(abs((*pRes).numerator),(*pRes).denominator);
    (*pRes).numerator/=g;
    (*pRes).denominator/=g;
    if((*pRes).numerator==0) (*pRes).denominator=1;
    if((*pRes).denominator==0) (*pRes).numerator=1;
    printFr(pFr1,pFr2,pRes,'-');
}

void multFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes)
{
    int a1,b1,a2,b2,g;
    a1=(*pFr1).numerator; b1=(*pFr1).denominator;
    a2=(*pFr2).numerator; b2=(*pFr2).denominator;
    (*pRes).numerator=a1*a2;
    (*pRes).denominator=b1*b2;
    g=gcd(abs((*pRes).numerator),(*pRes).denominator);
    (*pRes).numerator/=g;
    (*pRes).denominator/=g;
    if((*pRes).numerator==0) (*pRes).denominator=1;
    if((*pRes).denominator==0) (*pRes).numerator=1;
    printFr(pFr1,pFr2,pRes,'*');
}

void divFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes)
{
    int a1,b1,a2,b2,g;
    a1=(*pFr1).numerator; b1=(*pFr1).denominator;
    a2=(*pFr2).numerator; b2=(*pFr2).denominator;
    (*pRes).numerator=a1*b2;
    (*pRes).denominator=b1*a2;
    g=gcd(abs((*pRes).numerator),(*pRes).denominator);
    (*pRes).numerator/=g;
    (*pRes).denominator/=g;
    if((*pRes).numerator==0) (*pRes).denominator=1;
    if((*pRes).denominator==0) (*pRes).numerator=1;
    printFr(pFr1,pFr2,pRes,'/');
}

int main()
{
    FRACTION a,b,res;
    int g;
    getFr(&a);
    getFr(&b);
    g=gcd(a.numerator,a.denominator);
    a.numerator/=g; a.denominator/=g;
    g=gcd(b.numerator,b.denominator);
    b.numerator/=g; b.denominator/=g;
    if(a.numerator==0) a.denominator=1;
    if(b.numerator==0) b.denominator=1;
    addFr(&a,&b,&res);
    subFr(&a,&b,&res);
    multFr(&a,&b,&res);
    divFr(&a,&b,&res);
}
