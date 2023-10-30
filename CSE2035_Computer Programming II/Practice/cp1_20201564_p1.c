#include<stdio.h>

int main()
{
    int a,b,c;
    int *pa, *pb, *pc;
    int *tmp;
    int *max, *min;
    scanf("%d%d%d",&a,&b,&c);
    pa=&a, pb=&b, pc=&c;
    tmp=*pa > *pb ? pa : pb;
    max=*tmp> *pc ? tmp: pc;

    tmp=*pa < *pb ? pa : pb;
    min=*tmp< *pc ? tmp: pc;
    printf("%d %d\n%#x %#x",*min,*max,min,max);
}
