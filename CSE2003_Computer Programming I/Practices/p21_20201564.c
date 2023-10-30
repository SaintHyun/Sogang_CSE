#include<stdio.h>

int main()
{
    int n,i,j=1,a,b,c;
    printf("Input: ");
    scanf("%d",&n);
    i=1;
    while(i<=n)
    {
        j=1;
        while(j<=n-i+1)
        {
            printf(" ");
            j++;
        }
        while(j>n-i+1 && j<=n+i)
        {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
}
