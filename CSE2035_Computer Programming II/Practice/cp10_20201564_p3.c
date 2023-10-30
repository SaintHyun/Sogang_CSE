#include<stdio.h>

int main()
{
    char a[210],A[210];
    char B[210]={0,};
    int i,j,k,len;
    printf("Input String : ");
    fgets(a,210,stdin);
    printf("- Result -\n");
    for(len=0; ; len++)
    {
        A[len+1]=a[len];
        if(a[len]==0) break;
    }
    i=1;
    A[0]=' ';
    while(i<=len)
    {
        if(A[i]!=' ' && A[i-1]==' ')
        {
            for(j=i; ; j++)
            {
                if(A[j]==' ' || A[j]==0 || A[j]=='\n') break;
                B[j-i]=A[j];
            }
            printf("\t%s\n",B);
            for(j=0; j<210; j++)
            {
                //if(B[j]!=0) printf("%d ",B[j]);
                B[j]=0;
            }
            //printf("\n");
        }
        i++;
    }
}
