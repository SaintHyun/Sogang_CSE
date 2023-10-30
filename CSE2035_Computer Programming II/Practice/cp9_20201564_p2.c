#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int len,i,j,k,g=0,l;
    int dig=0;
    char *a;
    a=(char *)calloc(1002,sizeof(char));
    scanf("%s",a);
    for(i=0; i<1002; i++)
    {
        if(*(a+i)==0) break;
    }
    len=i-1;
    for(i=0; i<=len; i++)
    {
        if(*(a+i)<'0' || *(a+i)>'9')
        {
            //*(b+g)=*(a+i);
            g++;
        }
        else if(*(a+i)>='0' && *(a+i)<='9')
        {
            dig=0;
            j=i;
            while(*(a+j)>='0' && *(a+j)<='9')
            {
                j++;
            }
            j--;
            for(k=i; k<=j; k++)
            {
                dig+=(*(a+k)-'0') * pow(10,j-k);
            }
            for(k=0; k<dig; k++)
            {
                for(l=i-g; l<i; l++)
                {
                    printf("%c",*(a+l));
                }
            }
            i=j;
            g=0;
        }
    }
    free(a);
}
