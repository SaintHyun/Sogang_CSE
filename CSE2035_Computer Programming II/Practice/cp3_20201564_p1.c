#include<stdio.h>

void shift_n_left(int *a, int n)
{
    int i;
    for(i=0; i<10; i++)
    {
        if(*(a+i)>10-n) *(a+i)-=10-n;
        else if(*(a+i)<=10-n) *(a+i)+=n;
    }

}

void shift_n_right(int *a, int n)
{
    int i;
    for(i=9; i>=0; i--)
    {
        if(*(a+i)>n) *(a+i)-=n;
        else if(*(a+i)<=n) *(a+i)+=10-n;
    }
}

void print_array(int *a)
{
    int i;
    for(i=0; i<10; i++)
    {
        printf("%d ",*(a+i));
    }
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==0) shift_n_left(a,n);
    else if(k==1) shift_n_right(a,n);
    print_array(a);
    return 0;
}
