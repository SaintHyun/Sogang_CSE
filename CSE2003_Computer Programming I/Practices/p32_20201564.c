#include<stdio.h>

float avg(int A[])
{
    return (float)(0.15*A[1]+0.4*A[2]+0.2*A[3]+0.2*A[4]+0.05*A[5]);
}

int main()
{
    FILE *i1, *o;
    int n,i,j,k;
    char st[20][100];
    int sc[20][6];
    i1=fopen("input.txt","r");
    o=fopen("out.txt","w");
    fscanf(i1,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(i1,"%s",st[i]);
    }
    for(i=0; i<n; i++)
    {
        fscanf(i1,"%d%d%d%d%d",&sc[i][1],&sc[i][2],&sc[i][3],&sc[i][4],&sc[i][5]);
    }
    for(i=0; i<n; i++)
    {
        fprintf(o,"%s 의 최종 점수는 %.2f\n",st[i],avg(sc[i]));
    }
    fclose(i1); fclose(o);
}
