#include<stdio.h>

int main()
{
    FILE *in, *out;
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int b[101][101],t[101][101],max=-987654;
    int d[101];
    int sof;
    int i,j,k,n,x;
    int digit=10,m=1;
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            b[i][j]=-1;
            d[i]=-1;
            t[i][j]=-1;
        }
    }
    fscanf(in,"%d",&n);
    for(i=1; ; i++)
    {
        fscanf(in,"%d",&k);
        if(feof(in)!=0) break;
        if(max<k) max=k;
        d[k%10]+=1;
        b[d[k%10]][k%10]=k;
    }
    while(max>0)
    {
        max/=10;
        m*=10;
    }
    m/=10;
    for(i=0; i<100; i++)
    {
        d[i]=-1;
    }
    while(digit<=m)
    {
        for(i=0; i<10; i++)
        {
            for(j=0; j<100; j++)
            {
                if(b[j][i]!=-1)
                {
                    x=(b[j][i]%(digit*10)-b[j][i]%digit)/digit;
                    d[x]+=1;
                    t[d[x]][x]=b[j][i];
                }
            }
        }
        for(i=0; i<100; i++)
        {
            for(j=0; j<10; j++)
            {
                b[i][j]=t[i][j];
                t[i][j]=-1;
                d[i]=-1;
            }

        }
        digit*=10;

    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<100; j++)
        {
            if(b[j][i]!=-1) fprintf(out,"%d ",b[j][i]);
        }
    }
    fclose(in); fclose(out);
}
