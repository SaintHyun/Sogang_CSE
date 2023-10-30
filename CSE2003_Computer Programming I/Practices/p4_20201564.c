#include<stdio.h>

int main()
{
    int a;
    int b;
    printf("°¡°Ý : ");
    scanf("%d",&a);
    printf("³³ÀÔ°³¿ù¼ö\t:%10d%10d\n",3,6);
    b=a*1.05*1.05*1.05;
    printf("ÃÑ³³ÀÔ±Ý\t:%10d%10d\n",a,b);
    printf("¿ùº°³³ÀÔ±Ý\t:%10.2f%10.2f\n",(float)a/3,(float)b/6);
}
