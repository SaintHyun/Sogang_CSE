#include<stdio.h>

int main()
{
    char a[510], A[510];
    char B[510];
    printf("Text : ");
    fgets(a,510,stdin);
    printf("Word : ");
    fgets(B,510,stdin);
    int i,j,k,len,cnt=0;
    A[0]=' ';
    for(len=0; ; len++)
    {
        A[len+1]=a[len];
        if(B[len]=='\n') B[len]=0;
        if(a[len]==0) break;
    }
    i=1;
    while(i<=len)
    {
        if(A[i]!=' ' && A[i-1]==' ')
        {
            for(j=i; ; j++)
            {
                if(B[j-i]==0 && (A[j]==' ' || A[j]==0))
                {
                    cnt++;
                    break;
                }
                if(A[j]!=B[j-i]) break;
            }
        }
        i++;
    }
    printf("Number of '%s' : %d",B,cnt);
}
