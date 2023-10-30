#include<stdio.h>
#include<stdlib.h>

int determinant(int **a)
{
    if(a[0][0]*a[1][1]-a[0][1]*a[1][0]!=0)
    {
        printf("Invertible Matrix\n");
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    }
    else
    {
        printf("Singular Matrix");
        return 0;
    }
}

int main()
{
    int **a;
    int d;
    double **b;
    a=(int **)malloc(sizeof(int*)*2);
    a[0]=(int *)malloc(sizeof(int)*2);
    a[1]=(int *)malloc(sizeof(int)*2);
    b=(double **)malloc(sizeof(double*)*2);
    b[0]=(double *)malloc(sizeof(double)*2);
    b[1]=(double *)malloc(sizeof(double)*2);
    scanf("%d%d%d%d",&a[0][0],&a[0][1],&a[1][0],&a[1][1]);
    d=determinant(a);

    if(d!=0)
    {
        b[0][0]=(double)a[1][1]/d;
        b[0][1]=(double)a[0][1]/d *(-1);
        b[1][0]=(double)a[1][0]/d *(-1);
        b[1][1]=(double)a[0][0]/d;
        printf("%.2lf %.2lf\n%.2lf %.2lf",b[0][0],b[0][1],b[1][0],b[1][1]);
    }
    else return 0;

    free(a[0]),free(a[1]),free(a);
    free(b[0]),free(b[1]),free(b);
}
