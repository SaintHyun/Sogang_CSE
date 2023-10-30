#include<stdio.h>

void dec2oct(int *, int *, int *, int *, int);
void dec2hex(char *, char *, char *, int);
char digit2hex(int);

int main()
{
    int o1,o2,o3,o4;
    char h1,h2,h3;
    int a;
    scanf("%d",&a);
    printf("%04o\n",a);
    dec2oct(&o1,&o2,&o3,&o4,a);
    printf("%d%d%d%d\n",o1,o2,o3,o4);
    printf("%03X\n",a);
    dec2hex(&h1,&h2,&h3,a);
    printf("%c%c%c",h1,h2,h3);
}

void dec2oct(int *a, int*b, int*c, int*d,int n)
{
    *a=n/512;
    *b=(n%512)/64;
    *c=(n%512)%64/8;
    *d=n%512%64%8;
}

void dec2hex(char *a, char*b, char*c,int n)
{
    *a=digit2hex(n/256);
    *b=digit2hex(n%256/16);
    *c=digit2hex(n%256%16);
}

char digit2hex(int t)
{
    if(t>=10) return t+55;
    else return t+48;
}
