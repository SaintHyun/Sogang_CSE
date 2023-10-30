#include<stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void sort(int *a, int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(*(a+i) > *(a+j))
            {
                swap((a+i),(a+j));
            }
        }
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
    int n,i;
    int a[1010];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }
    sort(a,n);
    print_array(a,n);
}
