#include<stdio.h>

int main()
{
    FILE *i1, *i2, *o;
    char p,a1[50],a2[50],A[1200],B[1200];
    int i=0,la=0,lb=0,cnt=0;
    double r=0;
    printf("Input first file name: ");
    scanf("%s",a1);
    printf("Input second file name: ");
    scanf("%s",a2);
    i1=fopen(a1,"r");
    i2=fopen(a2,"r");
    o=fopen("output","w");
    while(1)
    {
        p=fgetc(i1);
        if(p=='\n' || p==' ') continue;
        if(p==EOF)
        {
            la=i;
            break;
        }
        A[i]=p;
        i++;
    }
    i=0;
    while(1)
    {
        p=fgetc(i2);
        if(p=='\n' || p==' ') continue;
        if(p==EOF)
        {
            lb=i;
            break;
        }
        B[i]=p;
        i++;
    }
    if(la>lb)
    {
        la=lb;
    }
    for(i=0; i<la; i++)
    {
        if(A[i]==B[i]) cnt++;
    }
    fprintf(o,"Total character: %d\nSame character: %d\n",la,cnt);
    fprintf(o,"%.3lf",100*(float)(cnt)/(float)la);
    fclose(i1);
    fclose(i2);
    fclose(o);
}
