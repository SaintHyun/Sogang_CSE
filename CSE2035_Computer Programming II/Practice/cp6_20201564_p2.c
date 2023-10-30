#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    int i,j;
    char *a, *b, *c;
    int size=51,l=48,k;
    a=(char *)calloc(size,sizeof(char));
    b=(char *)calloc(size,sizeof(char));
    c=(char *)calloc(size+1,sizeof(char));
    scanf("%d%d",&n,&m);
    k= n>m ? n:m;
    scanf("\n");
    for(i=1+(k-n); i<=n+(k-n); i++)
    {
        scanf("%c",&a[i]);
        a[i]-=l;
    }
    scanf("\n");
    for(i=1+(k-m); i<=m+(k-m); i++)
    {
        scanf("%c",&b[i]);
        b[i]-=l;
    }
    for(i=k; i>0; i--)
    {
        if(a[i]+b[i]+c[i]>=10)
        {
            c[i]+=a[i]+b[i]-10;
            c[i-1]+=1;
        }
        else c[i]+=a[i]+b[i];
    }

    if(c[0]!=0)
    {
        for(i=0; i<=k; i++)
        {
            printf("%d",c[i]);
        }
    }
    else
    {
        for(i=1; i<=k; i++)
        {
            printf("%d",c[i]);
        }
    }
    free(a);free(b);free(c);
}
