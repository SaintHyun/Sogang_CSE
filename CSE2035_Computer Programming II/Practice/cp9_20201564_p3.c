#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,i,j,k=0,l,cnt=0;
    int x=0,y=0;
    scanf("%d%d",&n,&m);
    char *a,*b,*c,*ans;
    int maxlen=-9;
    a=(char *)calloc(22,sizeof(char));
    b=(char *)calloc(22,sizeof(char));
    c=(char *)calloc(22,sizeof(char));
    ans=(char *)calloc(22,sizeof(char));

    scanf("%s",a);
    scanf("%s",b);
    for(x=0; x<n; x++)
    {
        for(y=0; y<m; y++)
        {
            k=0;
            for(i=x,j=y; i<=n && j<=m; i++,j++)
            {

                if(*(a+i)==*(b+j))
                {
                    *(c+k)=*(a+i);
                    k++;
                }
                else if(*(a+i)!=*(b+j) || *(a+i)==0 || *(b+j)==0)
                {
                    //printf("%d\n",k);
                    if(maxlen<k)
                    {
                        for(l=0; l<=k; l++)
                        {
                            *(ans+l)=*(c+l);
                        }
                        maxlen=k;
                    }
                    for(l=0; l<k; l++) *(c+l)=0;
                }
                //if(*(a+i)==0 || *(b+j)==0) break;
            }
        }
    }
    printf("Longest Common Substring = %s",ans);
    free(a); free(b); free(c); free(ans);
}
