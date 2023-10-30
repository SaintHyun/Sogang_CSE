#include<stdio.h>

double calc(int *a, int n)
{
    int i,j;
    double b=0;
    for(i=0; i<n; i++)
    {
        b+=*(a+i);
    }
    return (double)b/n;
}

int main()
{
    int n,A[1010];
    int i,j;
    double avg=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",(A+i));
    }
    avg=calc(&A,n);
    printf("%.2lf",avg);
}
