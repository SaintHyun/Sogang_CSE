#include<stdio.h>

void q(char A[])
{
    int i=0;
    while(1)
    {
        if(A[i]>='a' && A[i]<='z') A[i]-=32;
        if(A[i]=='\n') return;
        i++;
    }
}

int main()
{
    char A[51];
    int i=0,j=0;
    while(1)
    {
        scanf("%c",&A[i]);
        if(A[i]=='\n') break;
        i++;
    }
    q(A);
    while(1)
    {
        printf("%c",A[j]);
        if(A[j]=='\n') break;
        j++;
    }
}
