#include<stdio.h>

int main()
{
    char a[1010],A[1010];
    int i,j,k,len=0;
    int cnt=0;
    fgets(a,1010,stdin);
    for(len=0; ; len++)
    {
        A[len+1]=a[len];
        if(a[len]==0) break;
    }
    i=1;
    len--;
    A[0]=' ';
    while(i<=len)
    {
        if(A[i]!=' ' && A[i-1]==' ')
        {
            cnt++;
        }
        i++;
    }
    printf("%d",cnt);
}
