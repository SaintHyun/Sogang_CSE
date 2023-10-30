#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
    float comps;
    int vec_size;
}vector;

typedef float VectorSize;
VectorSize vSize(vector *v)
{
    int n, i;
    float x=0;
    n=v[0].vec_size;
    for(i=1; i<=n; i++)
    {
        x+=v[i].comps*v[i].comps;
    }
    printf("%.2f\n",sqrt(x));
}
typedef float Distance;
Distance DistVector(vector *v1, vector *v2)
{
    int n,i;
    n=v1[0].vec_size;
    float x=0;
    for(i=1; i<=n; i++)
    {
        x+=(v1[i].comps-v2[i].comps)*(v1[i].comps-v2[i].comps);
    }
    printf("%.2f\n",sqrt(x));
}
typedef float Scalar;
Scalar innerProduct(vector *v1, vector *v2)
{
    int n, i;
    float x=0;
    n= v1[0].vec_size;
    for(i=1; i<=n; i++)
    {
        x+=(v1[i].comps)*(v2[i].comps);
    }
    printf("%.2f",x);
}

int main()
{
    vector *v1; vector *v2;
    int n,m;
    scanf("%d",&n);
    int i;
    v1=(vector*)malloc(sizeof(vector)*(n+1));
    v1[0].vec_size=n;
    for(i=1; i<=n; i++)
    {
        scanf("%f",&v1[i].comps);
        //printf("\n%f",v1[i].comps);
    }
    scanf("%d",&m);
    v2=(vector*)malloc(sizeof(vector)*(m+1));
    v2[0].vec_size=m;
    for(i=1; i<=m; i++)
    {
        scanf("%f",&v2[i].comps);
        //printf("\n%f",v1[i].comps);
    }
    vSize(v1);
    vSize(v2);
    if(v1[0].vec_size==v2[0].vec_size)
    {
        DistVector(v1,v2);
        innerProduct(v1,v2);
    }
}
