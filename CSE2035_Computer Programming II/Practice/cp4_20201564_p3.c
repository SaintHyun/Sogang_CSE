#include<stdio.h>

void count(int board[][100], int n, int m)
{
    int cnt=0,i,j,b[100][100];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            *(*(b+i)+j)=-1;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(*(*(board+i)+j)==0)
            {
                if(*(*(b+i)+j+1)==-1 && j+1<m)
                {
                    cnt++;
                    *(*(b+i)+j+1)=1;
                    *(*(board+i)+j+1)=2;
                }
                else if((*(*(b+i+1)+j)==-1 && i+1<n))
                {
                    cnt++;
                    *(*(b+i+1)+j)=1;
                    *(*(board+i+1)+j)=2;
                }
            }
            else if(*(*(board+i)+j)==1)
            {
                if(*(*(b+i+1)+j)==-1 && i+1<n)
                {
                    cnt++;
                    *(*(b+i+1)+j)=1;
                    *(*(board+i+1)+j)=2;
                }
                else if((*(*(b+i)+j+1)==-1 && j+1<m))
                {
                    cnt++;
                    *(*(b+i)+j+1)=1;
                    *(*(board+i)+j+1)=2;
                }
            }
        }
    }
    printf("%d",cnt);
}

int main()
{
    int n,m;
    int a[100][100];
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",(*(a+i)+j));
        }
    }
    count(a,n,m);
}
