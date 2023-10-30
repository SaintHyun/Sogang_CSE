#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    float coef;
    int expon;
}poly;

poly *poly_sum(int n, int m, poly *a, poly *b)
{
    int i,j,k=0,l=0;
    poly *c=(poly*)calloc(n+m+1,sizeof(poly));
    if(n>m)
    {
        c=a;
        k=n;
        for(i=1; i<=m; i++)
        {
            l=0;
            for(j=1; j<=n; j++)
            {
                if(c[j].expon==b[i].expon)
                {
                    c[j].coef+=b[i].coef;
                    l=1;
                }
            }
            if(l==0)
            {
                //printf("%d %d %d",k,b[j].expon,b[j].coef);
                k++;
                c[k].expon=b[i].expon;
                c[k].coef=b[i].coef;
            }
        }
    }
    else
    {
        c=b;
        k=m;
        for(i=1; i<=n; i++)
        {
            l=0;
            for(j=1; j<=m; j++)
            {
                if(c[j].expon==a[i].expon)
                {
                    c[j].coef+=a[i].coef;
                    l=1;
                }
            }
            if(l==0)
            {
                //printf("\n%d %d %d %d\n",k,j,a[j].expon,a[j].coef);
                k++;
                c[k].expon=a[i].expon;
                c[k].coef=a[i].coef;
            }
        }
    }
    //printf("\n%d\n",k);
    int t;
    for(i=1; i<=k-1; i++)
    {
        for(j=i+1; j<=k; j++)
        {
            if(c[i].expon>c[j].expon)
            {
                t=c[i].expon; c[i].expon=c[j].expon; c[j].expon=t;
                t=c[i].coef; c[i].coef=c[j].coef; c[j].coef=t;
            }
        }
    }
    c[0].expon=k;
    return c;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    poly *a; poly *b; poly *c;
    a=(poly*)calloc(n+1,sizeof(poly));
    b=(poly*)calloc(m+1,sizeof(poly));
    c=(poly*)calloc(n+m+1,sizeof(poly));
    int i;
    for(i=1; i<=n; i++)
    {
        scanf("%f%d",&a[i].coef,&a[i].expon);
    }
    for(i=1; i<=m; i++)
    {
        scanf("%f%d",&b[i].coef,&b[i].expon);
    }
    c=poly_sum(n,m,a,b);

    if(c[1].expon==0 && c[1].coef!=0)
    {
        printf("%.2f",c[1].coef);
    }
    else
    {
        printf("%.2fx^%d",c[1].coef,c[1].expon);
    }
    for(i=2; i<=c[0].expon; i++)
    {
        if(c[i].coef!=0 && c[i].expon!=0)
        {
            if(c[i].coef>0) printf("+%.2fx^%d",c[i].coef,c[i].expon);
            else if(c[i].coef<0) printf("%.2fx^%d",c[i].coef,c[i].expon);
        }
    }
}
