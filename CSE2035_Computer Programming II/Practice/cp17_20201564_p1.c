#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    double x;
    double y;
    double z;
    double r;
}SPHERE;

double Distance(SPHERE a, SPHERE b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

double CrossSectionArea(SPHERE a, SPHERE b)
{
    return 3.14*(a.r*a.r+b.r*b.r);
}

double SurfaceArea(SPHERE a, SPHERE b)
{
    return 3.14*4*(a.r*a.r+b.r*b.r);
}

double Volume(SPHERE a, SPHERE b)
{
    return 3.14*4/3*(a.r*a.r*a.r+b.r*b.r*b.r);
}

int main()
{
    SPHERE a,b;
    printf("Type First Sphere Coordinate : ");
    scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
    printf("Type First Sphere Radius : ");
    scanf("%lf",&a.r);
    printf("Type Second Sphere Coordinate : ");
    scanf("%lf%lf%lf",&b.x,&b.y,&b.z);
    printf("Type Second Sphere Radius : ");
    scanf("%lf",&b.r);
    double d;
    d=Distance(a,b);
    if(d>a.r+b.r)
    {
        printf("Sum of Cross Section Area : %.2lf\n",CrossSectionArea(a,b));
    }
    else if(d==a.r+b.r)
    {
        printf("Sum of Surface Area : %.2lf\n",SurfaceArea(a,b));
    }
    else
    {
        printf("Sum of Volume : %.2lf\n",Volume(a,b));
    }
}
