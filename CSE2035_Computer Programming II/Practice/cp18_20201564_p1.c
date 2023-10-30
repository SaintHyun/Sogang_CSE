#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union utemp
{
    int i;
    float f;
    double d;
};

typedef struct
{
    int type;
    char name[20];
    union utemp u;
}stemp;

void power(stemp *s)
{
    switch((*s).type)
    {
    case 1:
        (*s).u.i*=(*s).u.i;
        break;
    case 2:
        (*s).u.f*=(*s).u.f;
        break;
    case 3:
        (*s).u.d*=(*s).u.d;
        break;
    }
}

int main()
{
    int n;
    printf("Number of Iterations : ");
    scanf("%d",&n);

    int i;
    stemp *s=(stemp*)calloc(n+2,sizeof(stemp));
    for(i=1; i<=n; i++)
    {
        printf("Type [1 for int, 2 for float, 3 for double] : ");
        scanf("%d",&s[i].type);
        switch(s[i].type)
        {
        case 1:
            printf("Enter an integer value : ");
            scanf("%d",&s[i].u.i);
            strcpy(s[i].name,"integer");
            break;
        case 2:
            printf("Enter a float value : ");
            scanf("%f",&s[i].u.f);
            strcpy(s[i].name,"float");
            break;
        case 3:
            printf("Enter a double value : ");
            scanf("%lf",&s[i].u.d);
            strcpy(s[i].name,"double");
            break;
        }
    }
    printf("----------Result----------\n");
    for(i=1; i<=n; i++)
    {
        power(&s[i]);
        switch(s[i].type)
        {
        case 1:
           printf("%-10s: %d\n",s[i].name,s[i].u.i);
           break;
        case 2:
           printf("%-10s: %.4f\n",s[i].name,s[i].u.f);
           break;
        case 3:
           printf("%-10s: %.4lf\n",s[i].name,s[i].u.d);
           break;

        }
    }
}
