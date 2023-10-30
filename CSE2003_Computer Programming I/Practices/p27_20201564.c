#include<stdio.h>

int main()
{
    int A[11],i,max=-0x7fffffff,min=0x7fffffff,a;
    printf("Input (10 numbers): ");
    for(i=1; i<=10; i++)
    {
        scanf("%d",&A[i]);
        if(max<A[i]) max=A[i];
        if(min>A[i]) min=A[i];
    }
    for(i=1; i<=5; i++)
    {
        a=A[i];
        A[i]=A[10-i+1];
        A[10-i+1]=a;
    }
    for(i=1; i<=10; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\nMax: %d, Min: %d",max,min);
}
