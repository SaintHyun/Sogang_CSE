#include<stdio.h>
#include<stdlib.h>

int main()
{
    int len,i,j,pal=1;
    char *a;
    a=(char *)calloc(102,sizeof(char));
    scanf("%s",a);
    for(i=0; i<101; i++)
    {
        if(*(a+i)==0) break;
    }
    len=i-1;
    if(len%2==0)
    {
        for(i=0; i<len/2; i++)
        {
            if(*(a+i)!=*(a+len-i)) pal=0;
        }
    }
    else if(len%2==1)
    {
        for(i=0; i<=len/2; i++)
        {
            if(*(a+i)!=*(a+len-i)) pal=0;
        }
    }
    if(pal==1) printf("Palindrome.");
    else printf("Not palindrome.");
    free(a);
}
