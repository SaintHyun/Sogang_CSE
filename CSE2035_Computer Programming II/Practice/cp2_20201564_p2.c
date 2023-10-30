#include<stdio.h>

void f(int *Y, int *M, int *D, int X)
{
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    *D+=X;
    for( ; ; )
    {
        if(*D>m[*M])
        {
            *D-=m[*M];
            *M+=1;
        }
        else break;
        if(*M>12)
        {
            *M-=12;
            *Y+=1;
        }

    }

}

int main()
{
    int x;
    int y=2020,m=9,d=10;
    scanf("%d",&x);
    f(&y,&m,&d,x);
    printf("%04d³â %02d¿ù %02dÀÏ",y,m,d);
}
