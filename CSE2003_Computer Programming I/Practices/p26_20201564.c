#include <stdio.h>

int d=1,k=1;

int palindrome(int num, int digit)
{
    if(digit==k && (num/d)%10==(num/digit)%10)
    {
        return 1;
    }
    if((num/d)%10==(num/digit)%10)
    {
        d/=10;
        return palindrome(num,digit*10);
    }
    else return 0;
}

int main()
{
    int n,a,i,j;
    printf("Input: ");
    scanf("%d",&n);
    a=n;
    if(n<0)
    {
        printf("Input number cannot be negative.");
        return 0;
    }
    for(i=1; a>0; i++)
    {
        a/=10;
        d*=10;
    }
    d/=10;
    for(j=1; j<=(i-1)/2+(1?0:(i-1)%2==1);j++)
    {
        k*=10;
    }
    if(palindrome(n,1))
    {
        printf("%d is a palindrome number.",n);
        return 0;
    }
    else printf("%d is not a palindrome number.",n);

}
