#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter 2 nubmers: ");
    scanf("%d%d",&a,&b);
    int c=a+b, d,e,f,cnt=0;
    d=c/100, e=c%100/10;
    if(c>1000) cnt++;
    if(d>a/100+b/100) cnt++;
    if(e>(a%100/10+b%100/10)%10) cnt++;
    printf("%d carry operations",cnt);

}
