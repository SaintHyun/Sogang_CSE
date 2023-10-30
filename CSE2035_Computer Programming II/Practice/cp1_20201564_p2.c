#include<stdio.h>

void *f(void *pa, void *pb, int option)
{
    if(option==0)
    {
        return (*(int *)pa<*(int *)pb ? pa:pb);
    }
    if(option==1)
    {
        return (*(float *)pa<*(float *)pb ? pa:pb);
    }
    if(option==2)
    {
        return (*(double *)pa<*(double *)pb ? pa:pb);
    }
}

int main()
{
    int option;
    int a,b;
    float fa,fb;
    double da,db;
    void *pa,*pb,*ans;
    scanf("%d",&option);
    if(option==0)
    {
        scanf("%d%d",&a,&b);
        ans=f(&a,&b,option);
        printf("%d",*(int *)ans);
    }
    else if(option==1)
    {
        scanf("%f%f",&fa,&fb);
        pa=&fa; pb=&fb;
        ans=f(&fa,&fb,option);
        printf("%f",*(float *)ans);
    }
    else if(option==2)
    {
        scanf("%lf%lf",&da,&db);
        pa=&da; pb=&db;
        ans=f(&da,&db,option);
        printf("%lf",*(double *)ans);
    }
}
