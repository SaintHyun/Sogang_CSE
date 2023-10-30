#include<stdio.h>
#include<math.h>

int main()
{
    float a;
    scanf("%f",&a);
    printf("Use \">\": %d\n",(int)((a-floor(a))/0.5)>0);
    printf("Use \">=\": %d\n",(float)a-floor(a)>=0.5);
    printf("Use \"==\": %d\n",floor(a+0.5) ==floor(a)+1);
    printf("Use \"!=\": %d\n",  floor(a+0.5)!=floor(a));
}



