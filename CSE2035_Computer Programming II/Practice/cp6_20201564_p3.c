#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    char **pibo;
    int size=3000,l1=1,l2=1,t;
    int i,j;

    pibo=(char **)calloc(3000,sizeof(char));
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        pibo[i]=(char *)calloc(size,sizeof(char));
    }
    pibo[1][1]=1;
    pibo[2][1]=1;
    for(i=3; i<=n; i++)
    {
        for(j=1; j<=l1; j++)
        {
            if(pibo[i][j]+pibo[i-1][j]+pibo[i-2][j]>=10)
            {
                pibo[i][j]+=pibo[i-1][j]+pibo[i-2][j]-10;
                pibo[i][j+1]+=1;
            }
            else pibo[i][j]+=pibo[i-1][j]+pibo[i-2][j];
        }
        if(pibo[i][l1+1]!=0)
        {
            l1++;
        }
        else if(l1!=l2) l2++;
    }
    for(i=l1; i>=1; i--)
    {
        printf("%d",pibo[n][i]);
    }
    for(i=1; i<=n; i++)
    {
        free(pibo[i]);
    }
    free(pibo);
}
