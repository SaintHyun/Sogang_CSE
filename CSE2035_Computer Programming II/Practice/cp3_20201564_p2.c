#include<stdio.h>

void make_array(int *a, int *b, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(*(a+i)+1>n) *(b+i)=1;
        else *(b+i)=*(a+i)+1;
    }
}

void print_array(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ",*(a+i));
    }
}

int main()
{
    int a[12],b[12];
    int n;
    int i;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",(a+i));
    }
    make_array(a,b,n);
    print_array(b,n);
}
